const express = require('express');
const cors = require('cors');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');

const app = express();

// Middlewares básicos
app.use(cors());
app.use(express.json());

// Diretórios auxiliares
const TEMP_DIR = path.join(__dirname, 'temp');
// output na RAIZ, igual ao que o main.c usa ("output/<basename>.tm")
const OUTPUT_DIR = path.join(__dirname, '..', 'output');

// Garante que pastas existem
[TEMP_DIR, OUTPUT_DIR].forEach((dir) => {
  if (!fs.existsSync(dir)) fs.mkdirSync(dir, { recursive: true });
});

// Caminho dos executáveis (ficam na raiz do projeto)
const CMINUS_BIN = path.join(__dirname, '..', 'cminus');
const TM_BIN = path.join(__dirname, '..', 'tm');

// ====== NOVO: fontes do compilador para visualização ======
const SOURCE_ROOT = path.join(__dirname, '..');

const SOURCE_FILES = {
  'src/main.c': path.join(SOURCE_ROOT, 'src', 'main.c'),
  'src/cminus.l': path.join(SOURCE_ROOT, 'src', 'cminus.l'),
  'src/cminus.y': path.join(SOURCE_ROOT, 'src', 'cminus.y'),
  'src/analyze.c': path.join(SOURCE_ROOT, 'src', 'analyze.c'),
  'src/cgen.c': path.join(SOURCE_ROOT, 'src', 'cgen.c'),
  'src/symtab.c': path.join(SOURCE_ROOT, 'src', 'symtab.c'),
  'src/util.c': path.join(SOURCE_ROOT, 'src', 'util.c'),
  'include/globals.h': path.join(SOURCE_ROOT, 'include', 'globals.h'),
  'include/ast.h': path.join(SOURCE_ROOT, 'include', 'ast.h'),
  'include/symtab.h': path.join(SOURCE_ROOT, 'include', 'symtab.h'),
  'include/scan.h': path.join(SOURCE_ROOT, 'include', 'scan.h'),
  'include/analyze.h': path.join(SOURCE_ROOT, 'include', 'analyze.h'),
  'include/cgen.h': path.join(SOURCE_ROOT, 'include', 'cgen.h'),
  'include/util.h': path.join(SOURCE_ROOT, 'include', 'util.h')
};
// ===========================================================

// Checa se executáveis existem
if (!fs.existsSync(CMINUS_BIN)) {
  console.error('❌ Executável cminus não encontrado em:', CMINUS_BIN);
  console.error('   Rode "make" na raiz e deixe o binário cminus lá.');
}
if (!fs.existsSync(TM_BIN)) {
  console.warn('⚠️ Executável tm não encontrado em:', TM_BIN);
}

// Rota de compilação C-
app.post('/compile', (req, res) => {
  const { code } = req.body;

  if (typeof code !== 'string') {
    return res
      .status(400)
      .json({ success: false, stdout: '', stderr: 'Campo "code" ausente.', tmCode: '' });
  }

  const timestamp = Date.now();

  // Arquivo de entrada temporário (.c-) dentro de backend/temp
  const inputFile = path.join(TEMP_DIR, `input_${timestamp}.c-`);

  // Arquivo de saída .tm na RAIZ/output, seguindo o padrão do main.c
  const tmFile = path.join(OUTPUT_DIR, `input_${timestamp}.tm`);

  // Salva o código C- em arquivo
  fs.writeFileSync(inputFile, code);

  const cmd = `"${CMINUS_BIN}" "${inputFile}"`;
  console.log('📝 Compilando:', cmd);

  exec(
    cmd,
    {
      cwd: path.join(__dirname, '..'), // diretório de trabalho = raiz do projeto
      timeout: 8000,
      maxBuffer: 1024 * 1024
    },
    (error, stdout, stderr) => {
      let tmCode = '';

      // Tenta ler o .tm gerado
      if (fs.existsSync(tmFile)) {
        try {
          tmCode = fs.readFileSync(tmFile, 'utf8');
        } catch (e) {
          console.error('Erro lendo TM:', e);
        }
      } else {
        console.warn('⚠️ Arquivo TM não encontrado em:', tmFile);
      }

      const payload = {
        success: !error,
        stdout,
        stderr: error ? `${error.message}\n${stderr}` : stderr,
        tmCode
      };

      // Limpa arquivo de entrada .c-
      try {
        if (fs.existsSync(inputFile)) fs.unlinkSync(inputFile);
      } catch (e) {
        console.error('Erro removendo arquivo temporário:', e);
      }

      return res.json(payload);
    }
  );
});

// Rota de execução da TM
app.post('/run', (req, res) => {
  const { tmCode, input } = req.body;

  if (typeof tmCode !== 'string' || !tmCode.trim()) {
    return res
      .status(400)
      .json({ success: false, output: '', errors: 'tmCode vazio. Compile antes.' });
  }

  const timestamp = Date.now();
  const tmTempFile = path.join(TEMP_DIR, `program_${timestamp}.tm`);

  // Salva o código TM em arquivo temporário
  fs.writeFileSync(tmTempFile, tmCode);

  const cmd = `"${TM_BIN}" "${tmTempFile}"`;
  console.log('▶️ Executando TM:', cmd);

  const child = exec(
    cmd,
    {
      cwd: path.join(__dirname, '..'), // executa tm na raiz
      timeout: 10000,
      maxBuffer: 1024 * 1024
    },
    (error, stdout, stderr) => {
      const payload = {
        success: !error,
        output: stdout,
        errors: error ? `${error.message}\n${stderr}` : stderr
      };

      // Limpa TM temporário
      try {
        if (fs.existsSync(tmTempFile)) fs.unlinkSync(tmTempFile);
      } catch (e) {
        console.error('Erro removendo TM temporário:', e);
      }

      return res.json(payload);
    }
  );

  // A TM é interativa:
  // 1) 'g' -> executa até HALT
  // 2) durante a execução, IN lê os inputs seguintes
  // 3) 'q' -> sai do loop de comandos e encerra o simulador
  let stdinData = 'g\n';

  if (input && String(input).trim().length > 0) {
    stdinData += String(input).trimEnd() + '\n';
  }

  stdinData += 'q\n';

  if (child.stdin) {
    child.stdin.write(stdinData);
    child.stdin.end();
  }
});

// ====== NOVO: APIs para "visitar" o código do compilador ======

// Lista os arquivos disponíveis
app.get('/sources', (req, res) => {
  const files = Object.keys(SOURCE_FILES).map((key) => ({
    id: key,
    label: key
  }));
  res.json(files);
});

// Conteúdo de um arquivo
app.get('/sources/:id', (req, res) => {
  const id = decodeURIComponent(req.params.id);
  const filePath = SOURCE_FILES[id];

  if (!filePath) {
    return res.status(404).json({ error: 'Arquivo não permitido' });
  }

  try {
    const content = fs.readFileSync(filePath, 'utf8');
    res.json({ id, content });
  } catch (e) {
    console.error('Erro lendo fonte', id, e);
    res.status(500).json({ error: 'Erro ao ler arquivo' });
  }
});
// ===============================================================

// Sobe o servidor
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`🚀 Backend C- rodando em http://localhost:${PORT}`);
  console.log('CMINUS_BIN:', CMINUS_BIN);
  console.log('TM_BIN:', TM_BIN);
  console.log('TEMP_DIR:', TEMP_DIR);
  console.log('OUTPUT_DIR:', OUTPUT_DIR);
});
