# vibedrum ui: serves the page, lists the versions in work/, hands out notes from `vibedrum json`, takes drops and pastes.
# Local only. Edits happen in chat: Claude writes work/<song>.v<n>.mid and the page picks it up within a second.
import json, os, re, shutil, subprocess, sys, tempfile
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, unquote, urlparse

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WORK, BIN, PAGE = os.path.join(ROOT, 'work'), os.path.join(ROOT, 'build', 'vibedrum'), os.path.join(ROOT, 'ui', 'index.html')
VER = re.compile(r'^(.+)\.v(\d+)\.mid$')
PORT = 8790


def stem(name):   # any file name -> a safe song name
    return re.sub(r'[^A-Za-z0-9_-]+', '-', os.path.splitext(os.path.basename(name))[0]).strip('-') or 'song'


assert stem('../My Song (v2).mid') == 'My-Song-v2' and stem('???.mid') == 'song' and stem('a/b/../x.mid') == 'x'


def vibedrum(*args):
    r = subprocess.run([BIN, *args], capture_output=True, text=True)
    if r.returncode: raise ValueError(r.stderr.strip().removeprefix('vibedrum: ') or 'vibedrum failed')
    return r.stdout


def versions():   # the song whose newest version is newest, and all its versions in order
    files = [f for f in os.listdir(WORK) if VER.match(f)] if os.path.isdir(WORK) else []
    if not files: return None, [], 0
    mtime = lambda f: os.stat(os.path.join(WORK, f)).st_mtime_ns
    song = VER.match(max(files, key=mtime)).group(1)
    vs = sorted((f for f in files if VER.match(f).group(1) == song), key=lambda f: int(VER.match(f).group(2)))
    return song, vs, max(map(mtime, vs))


def save(src, name):   # copy a readable MIDI file in as work/<song>.v0.mid, the original is never touched
    vibedrum('json', src)   # raises unless the engine can read it
    os.makedirs(WORK, exist_ok=True)
    base = song = stem(name); i = 1
    while os.path.exists(os.path.join(WORK, song + '.v0.mid')): i += 1; song = f'{base}-{i}'
    shutil.copyfile(src, os.path.join(WORK, song + '.v0.mid'))
    return song


class H(BaseHTTPRequestHandler):
    def send(self, code, body, ctype='application/json'):
        b = body if isinstance(body, bytes) else body.encode()
        self.send_response(code)
        self.send_header('Content-Type', ctype); self.send_header('Content-Length', str(len(b))); self.send_header('Cache-Control', 'no-store')
        self.end_headers(); self.wfile.write(b)

    def do_GET(self):
        u = urlparse(self.path)
        try:
            if u.path == '/':
                with open(PAGE, 'rb') as f: return self.send(200, f.read(), 'text/html; charset=utf-8')
            if u.path == '/api/state':
                song, vs, stamp = versions()
                return self.send(200, json.dumps({'song': song, 'versions': vs, 'stamp': stamp}))
            if u.path == '/api/notes':
                f = parse_qs(u.query).get('f', [''])[0]
                if not VER.match(f) or os.path.basename(f) != f or not os.path.isfile(os.path.join(WORK, f)):
                    return self.send(404, json.dumps({'error': 'no such version: ' + f}))
                return self.send(200, vibedrum('json', os.path.join(WORK, f)))
            self.send(404, json.dumps({'error': 'not found'}))
        except ValueError as e:
            self.send(400, json.dumps({'error': str(e)}))

    def do_POST(self):
        try:
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
                    info = subprocess.run(['osascript', '-e', 'clipboard info'], capture_output=True, text=True).stdout.strip()
                    raise ValueError('No MIDI file on the clipboard. Copy the .mid in Finder, or drag it in. Clipboard holds: ' + (info or 'nothing'))
                return self.send(200, json.dumps({'song': save(path, path)}))
            self.send(404, json.dumps({'error': 'not found'}))
        except ValueError as e:
            self.send(400, json.dumps({'error': str(e)}))

    def log_message(self, fmt, *args):
        if '/api/state' not in self.requestline: super().log_message(fmt, *args)


if __name__ == '__main__':
    if not os.access(BIN, os.X_OK): sys.exit('build the engine first, see CLAUDE.md')
    print(f'vibedrum ui on http://localhost:{PORT}', flush=True)
    ThreadingHTTPServer(('127.0.0.1', PORT), H).serve_forever()
