# vibedrum ui: serves the page, lists the versions in work/, hands out notes from `vibedrum json`, takes drops and pastes.
# Local only. Edits happen in chat: Claude writes work/<song>.v<n>.mid and the page picks it up within a second.
import atexit, errno, itertools, json, os, re, shutil, signal, subprocess, sys, tempfile, threading, unicodedata
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, unquote, urlparse

ROOT = os.path.realpath(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))   # real path: start.sh compares it with `pwd -P`
WORK, BIN, PAGE = os.path.join(ROOT, 'work'), os.path.join(ROOT, 'build', 'vibedrum'), os.path.join(ROOT, 'ui', 'index.html')
VER = re.compile(r'^(.+)\.v(\d+)\.mid$')
PORT = int(os.environ.get('VIBEDRUM_PORT', 8790))   # the env var is for tests, the page and start.sh use 8790
TMP, WAVS, LOCK, SEQ = tempfile.mkdtemp(prefix='vibedrum-'), {}, threading.Lock(), itertools.count()   # WAVS: rendered files by (version, mtime), oldest first
atexit.register(shutil.rmtree, TMP, True)


def stem(name):   # any file name -> a safe song name, letters of any script kept, short enough for a file name
    return re.sub(r'[^\w-]+', '-', unicodedata.normalize('NFC', os.path.splitext(os.path.basename(name))[0]))[:100].strip('-') or 'song'


assert stem('../My Song (v2).mid') == 'My-Song-v2' and stem('???.mid') == 'song' and stem('a/b/../x.mid') == 'x'
assert stem('שיר שלי.mid') == 'שיר-שלי' and len(stem('a' * 300 + '.mid')) == 100


def span(h, n):   # Range header over n bytes -> (first, last) inclusive, False if it starts past the end, None to send it all
    m = re.fullmatch(r'bytes=(\d*)-(\d*)', (h or '').strip())
    if not m or m.group(1) == m.group(2) == '': return None   # none, several ranges or garbage: the whole file is a valid answer
    a, b = m.groups()
    a, b = (max(0, n - int(b)), n - 1) if not a else (int(a), min(int(b or n - 1), n - 1))   # 'bytes=-k' is the last k bytes
    return False if a >= n else (a, b) if a <= b else None


assert [span(h, 10) for h in ('bytes=2-5', 'bytes=-3', 'bytes=4-', 'bytes=0-99', 'bytes=10-', 'bytes=0-1,5-6', None)] == [(2, 5), (7, 9), (4, 9), (0, 9), False, None, None]


def mtime(p):   # st_mtime_ns, 0 when the file is gone
    try: return os.stat(p).st_mtime_ns
    except OSError: return 0


def run(*cmd):   # errors='replace': a DAW's marker text need not be UTF-8. 60 s: a huge or broken file must not hold the page for ever
    try: return subprocess.run(cmd, capture_output=True, text=True, errors='replace', timeout=60)
    except subprocess.TimeoutExpired: raise ValueError(f'{os.path.basename(cmd[0])} took more than 60 seconds. The file may be too long or damaged.')


def vibedrum(*args):
    r = run(BIN, *args)
    if r.returncode: raise ValueError(r.stderr.strip().removeprefix('vibedrum: ') or 'vibedrum failed')
    return r.stdout


def versions():   # the song whose newest version is newest, and all its versions in order
    try: names = os.listdir(WORK)
    except OSError: names = []   # no work/ yet
    stamps = {f: t for f in names if VER.match(f) and (t := mtime(os.path.join(WORK, f)))}   # a file can vanish between listdir and stat
    if not stamps: return None, [], 0
    song = VER.match(max(stamps, key=stamps.get)).group(1)
    vs = sorted((f for f in stamps if VER.match(f).group(1) == song), key=lambda f: int(VER.match(f).group(2)))
    return song, vs, max(stamps[f] for f in vs)


def version(query):   # ?f=<song>.v<n>.mid, only ever a file directly inside work/
    f = parse_qs(query).get('f', [''])[0]
    if not VER.match(f) or os.path.basename(f) != f or not os.path.isfile(os.path.join(WORK, f)): raise ValueError('no such version: ' + f)
    return os.path.join(WORK, f)


def mapargs(path):   # work/<song>.map is a custom drum map: it goes to the engine as --map
    m = os.path.join(WORK, VER.match(os.path.basename(path)).group(1) + '.map')
    return ['--map', m] if os.path.isfile(m) else []


def audio(path):   # the version through the GM synth of `vibedrum render`, as an open WAV file. One render per (version, mtime), the last 8 kept in TMP
    m = mapargs(path); key = (os.path.basename(path), mtime(path), mtime(m[1]) if m else 0)
    if not key[1]: raise ValueError('no such version: ' + key[0])
    with LOCK:   # ponytail: one lock for every version, a second request waits for the render of the first instead of making its own
        wav = WAVS.pop(key, None)
        if not wav:
            wav = os.path.join(TMP, f'{next(SEQ)}.wav')
            try: vibedrum('render', path, '-o', wav, *m)
            except ValueError:
                if os.path.exists(wav): os.remove(wav)
                raise
            while len(WAVS) >= 8: os.remove(WAVS.pop(next(iter(WAVS))))
        WAVS[key] = wav   # last in: the one longest unused is first
        return open(wav, 'rb')   # opened under the lock, so an eviction cannot pull it away


def save(src, name):   # copy a readable MIDI file in as work/<song>.v0.mid, the original is never touched
    vibedrum('json', src)   # raises unless the engine can read it
    os.makedirs(WORK, exist_ok=True)
    base = song = stem(name); i = 1
    while os.path.exists(os.path.join(WORK, song + '.v0.mid')): i += 1; song = f'{base}-{i}'
    shutil.copyfile(src, os.path.join(WORK, song + '.v0.mid'))
    return song


class H(BaseHTTPRequestHandler):
    timeout = 30   # a client that stalls half way through a request is dropped, not kept for ever

    def send(self, code, body, ctype='application/json', extra=()):
        b = body if isinstance(body, bytes) else body.encode()
        try:
            self.send_response(code)
            self.send_header('Content-Type', ctype); self.send_header('Content-Length', str(len(b))); self.send_header('Cache-Control', 'no-store')
            for k, v in extra: self.send_header(k, v)
            self.end_headers(); self.wfile.write(b)
        except (BrokenPipeError, ConnectionResetError): self.close_connection = True   # the browser gave up on the download

    def deny(self, post):   # True once it has answered 403. Host: a site rebound to 127.0.0.1 sends its own name. X-Vibedrum: a custom header makes
        if not re.fullmatch(r'(localhost|127\.0\.0\.1)(:\d+)?', self.headers.get('Host', '').lower()): why = f'wrong Host, use http://localhost:{PORT}'   # another site's
        elif post and self.headers.get('X-Vibedrum') != '1': why = 'not from the vibedrum page'   # POST need a preflight, and there is no do_OPTIONS
        else: return False
        self.send(403, json.dumps({'error': why}))
        return True

    def do_GET(self):
        if self.deny(False): return
        u = urlparse(self.path)
        try:
            if u.path == '/':
                with open(PAGE, 'rb') as f: return self.send(200, f.read(), 'text/html; charset=utf-8')
            if u.path == '/favicon.ico':   # asked for on every load, there is none
                self.send_response(204); return self.end_headers()
            if u.path == '/api/state':
                song, vs, stamp = versions()
                return self.send(200, json.dumps({'song': song, 'versions': vs, 'stamp': stamp, 'root': ROOT}, ensure_ascii=False))
            if u.path == '/api/notes':
                p = version(u.query)
                return self.send(200, vibedrum('json', p, *mapargs(p)))
            if u.path == '/api/audio':   # Safari plays only what answers Range, so: 206 for a range, 200 with Accept-Ranges for the rest
                with audio(version(u.query)) as w:
                    n = os.fstat(w.fileno()).st_size; r = span(self.headers.get('Range'), n)
                    if r is False: return self.send(416, b'', extra=[('Content-Range', f'bytes */{n}')])
                    a, b = r or (0, n - 1); w.seek(a)
                    return self.send(206 if r else 200, w.read(b - a + 1), 'audio/wav', [('Accept-Ranges', 'bytes')] + [('Content-Range', f'bytes {a}-{b}/{n}')] * bool(r))
            self.send(404, json.dumps({'error': 'not found'}))
        except ValueError as e:
            self.send(400, json.dumps({'error': str(e)}))

    def do_POST(self):
        if self.deny(True): return
        u = urlparse(self.path)
        try:
            if u.path == '/api/copy':   # the version onto the macOS clipboard as a file, through `vibedrum clip`
                vibedrum('clip', version(u.query))
                return self.send(200, json.dumps({'ok': True}))
            if self.path == '/api/drop':
                n = int(self.headers.get('Content-Length', 0))
                if not 0 < n <= 20_000_000: raise ValueError('expected a MIDI file under 20 MB')
                with tempfile.NamedTemporaryFile(suffix='.mid') as t:
                    t.write(self.rfile.read(n)); t.flush()
                    song = save(t.name, unquote(self.headers.get('X-Name', 'song.mid')))
                return self.send(200, json.dumps({'song': song}))
            if self.path == '/api/paste':
                try: path = vibedrum('clip').strip()
                except ValueError:   # tell what IS on the clipboard, so a DAW's private format can be read later
                    info = run('osascript', '-e', 'clipboard info').stdout.strip()
                    raise ValueError('No MIDI file on the clipboard. Copy the .mid in Finder, or drag it in. Clipboard holds: ' + (info or 'nothing'))
                return self.send(200, json.dumps({'song': save(path, path)}))
            self.send(404, json.dumps({'error': 'not found'}))
        except ValueError as e:
            self.send(400, json.dumps({'error': str(e)}))

    def log_message(self, fmt, *args):
        if '/api/state' not in getattr(self, 'requestline', ''): super().log_message(fmt, *args)   # a timed out request has no requestline yet


if __name__ == '__main__':
    if not os.access(BIN, os.X_OK): sys.exit('build the engine first, see CLAUDE.md')
    try: srv = ThreadingHTTPServer(('127.0.0.1', PORT), H)
    except OSError as e:
        if e.errno != errno.EADDRINUSE: raise
        sys.exit(f'Port {PORT} is already in use by another program. Quit that program and run this again.')
    signal.signal(signal.SIGTERM, lambda *_: sys.exit(0))   # a plain `kill` runs the atexit clean up of the temp WAVs too
    print(f'vibedrum ui on http://localhost:{PORT}', flush=True)
    try: srv.serve_forever()
    except KeyboardInterrupt: print('\nvibedrum ui stopped' if sys.stdout.isatty() else 'vibedrum ui stopped')   # the leading newline ends the terminal's ^C line
