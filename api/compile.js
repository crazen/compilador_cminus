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

  const { code } = req.body || {};
  if (!code) {
    return res.status(400).json({ error: 'No code provided' });
  }

  const ts = Date.now();
  const inputPath = `/tmp/input_${ts}.cm`;
  const outputPath = `/tmp/output_${ts}.tm`;

  try {
    fs.writeFileSync(inputPath, code, 'utf8');

    const cminusPath = path.join(process.cwd(), 'bin', 'cminus');
    fs.chmodSync(cminusPath, 0o755);

    const child = spawn(cminusPath, [inputPath, outputPath]);

    let stdout = '';
    let stderr = '';

    child.stdout.on('data', (d) => { stdout += d.toString(); });
    child.stderr.on('data', (d) => { stderr += d.toString(); });

    child.on('close', (exitCode) => {
      let tmCode = '';
      if (fs.existsSync(outputPath)) {
        tmCode = fs.readFileSync(outputPath, 'utf8');
      }

      try {
        if (fs.existsSync(inputPath)) fs.unlinkSync(inputPath);
        if (fs.existsSync(outputPath)) fs.unlinkSync(outputPath);
      } catch (_) {}

      res.status(200).json({
        success: exitCode === 0,
        stdout,
        stderr,
        tmCode
      });
    });
  } catch (err) {
    res.status(500).json({ error: String(err) });
  }
};
