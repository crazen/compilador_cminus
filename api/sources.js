const fs = require('fs');
const path = require('path');

const SOURCE_FILES = [
  'src/main.c',
  'src/cminus.l',
  'src/cminus.y',
  'src/analyze.c',
  'src/cgen.c',
  'src/symtab.c',
  'src/util.c',
  'include/ast.h',
  'include/symtab.h',
  'include/globals.h',
  'include/scan.h',
  'include/analyze.h',
  'include/cgen.h',
  'include/util.h'
];

module.exports = async (req, res) => {
  res.setHeader('Access-Control-Allow-Origin', '*');

  const id = (req.query && req.query.id) || null;

  if (req.method === 'GET' && !id) {
    const files = SOURCE_FILES.map((f) => ({
      id: f,
      name: path.basename(f),
      path: f
    }));
    return res.status(200).json(files);
  }

  if (req.method === 'GET' && id) {
    const filePath = path.join(process.cwd(), id);
    if (!fs.existsSync(filePath)) {
      return res.status(404).json({ error: 'File not found' });
    }
    const content = fs.readFileSync(filePath, 'utf8');
    return res.status(200).json({ content });
  }

  res.status(405).json({ error: 'Method not allowed' });
};
