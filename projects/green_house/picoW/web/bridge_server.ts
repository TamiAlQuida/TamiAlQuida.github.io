import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import { spawn } from 'node:child_process';
import { fileURLToPath } from 'node:url';

// Minimal TypeScript Bridge Server
// Run with: node --experimental-strip-types bridge_server.ts (for newer Node versions)
// Or simply: node bridge_server.ts (if Node 23+)

const PORT = 8000;
const __dirname = path.dirname(fileURLToPath(import.meta.url));

const scripts: Record<string, string> = {
    python: "/home/tom/TamiAlQuida.github.io/projects/old_historic/bolan.py",
    bash: "/home/tom/TamiAlQuida.github.io/projects/old_historic/bme280_sensor.sh",
    cpp: "/home/tom/TamiAlQuida.github.io/projects/old_historic/controller.cpp"
};

const MIME_TYPES: Record<string, string> = {
    '.html': 'text/html',
    '.js': 'text/javascript',
    '.css': 'text/css',
    '.json': 'application/json',
    '.png': 'image/png',
    '.jpg': 'image/jpg',
    '.gif': 'image/gif',
    '.svg': 'image/svg+xml',
};

const server = http.createServer((req, res) => {
    // Set CORS headers for all responses
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

    // Handle preflight OPTIONS
    if (req.method === 'OPTIONS') {
        res.writeHead(204);
        res.end();
        return;
    }

    // Handle Script Execution
    if (req.method === 'POST' && req.url === '/run-script') {
        let body = '';
        req.on('data', chunk => { body += chunk; });
        req.on('end', () => {
            try {
                const data = JSON.parse(body);
                const scriptType = data.type as string;

                if (scripts[scriptType]) {
                    const targetPath = scripts[scriptType];
                    console.log(`Executing ${scriptType} script: ${targetPath}`);

                    let execCmd = '';
                    if (scriptType === 'python') {
                        execCmd = `python3 ${targetPath}; echo; echo 'Process finished. Press Enter to close...'; read`;
                    } else if (scriptType === 'bash') {
                        execCmd = `bash ${targetPath}; echo; echo 'Process finished. Press Enter to close...'; read`;
                    } else {
                        execCmd = `echo 'C++ Script info: ${targetPath}'; echo; echo 'Press Enter to close...'; read`;
                    }

                    // Launch Alacritty terminal
                    spawn('alacritty', ['-e', 'bash', '-c', execCmd], {
                        detached: true,
                        stdio: 'ignore'
                    }).unref();

                    res.writeHead(200, { 'Content-Type': 'application/json' });
                    res.end(JSON.stringify({ status: 'success', message: `Started ${scriptType}` }));
                } else {
                    res.writeHead(400, { 'Content-Type': 'application/json' });
                    res.end(JSON.stringify({ status: 'error', message: 'Unknown script type' }));
                }
            } catch (e) {
                res.writeHead(400, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({ status: 'error', message: 'Invalid JSON' }));
            }
        });
        return;
    }

    // Handle Static Files
    let filePath = req.url === '/' ? '/index.html' : req.url || '';
    const fullPath = path.join(__dirname, filePath);

    const ext = path.extname(fullPath).toLowerCase();
    const contentType = MIME_TYPES[ext] || 'application/octet-stream';

    fs.readFile(fullPath, (error, content) => {
        if (error) {
            if (error.code === 'ENOENT') {
                res.writeHead(404);
                res.end('File Not Found');
            } else {
                res.writeHead(500);
                res.end(`Server Error: ${error.code}`);
            }
        } else {
            res.writeHead(200, { 'Content-Type': contentType });
            res.end(content, 'utf-8');
        }
    });
});

server.listen(PORT, '0.0.0.0', () => {
    console.log('==================================================');
    console.log(`  TYPESCRIPT BRIDGE SERVER RUNNING ON http://localhost:${PORT}`);
    console.log('  1. Serves static files');
    console.log('  2. Runs local scripts via alacritty');
    console.log('==================================================');
});
