const { spawn } = require('child_process');
const fs = require('fs');
const path = require('path');

module.exports = async (req, res) => {
  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'POST, OPTIONS');
  res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

  if (req.method === 'OPTIONS') {
    return res.status(200).end();
  }

  if (req.method !== 'POST') {
    return res.status(405).json({ error: 'Method not allowed' });
  }

  const { tmCode, input } = req.body || {};
  if (!tmCode) {
    return res.status(400).json({ error: 'No TM code provided' });
  }

  const ts = Date.now();
  const tmPath = `/tmp/program_${ts}.tm`;

  try {
    fs.writeFileSync(tmPath, tmCode, 'utf8');

    const tmBinaryPath = path.join(process.cwd(), 'bin', 'tm');
    fs.chmodSync(tmBinaryPath, 0o755);

    const child = spawn(tmBinaryPath, [tmPath]);

    let output = '';
    let errors = '';

    if (input) {
      child.stdin.write(input);
      child.stdin.end();
    }

    child.stdout.on('data', (d) => { output += d.toString(); });
    child.stderr.on('data', (d) => { errors += d.toString(); });

    child.on('close', (exitCode) => {
      try {
        if (fs.existsSync(tmPath)) fs.unlinkSync(tmPath);
      } catch (_) {}

      res.status(200).json({
        success: exitCode === 0,
        output,
        errors
      });
    });
  } catch (err) {
    res.status(500).json({ error: String(err) });
  }
};
