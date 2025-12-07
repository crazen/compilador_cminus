import { useState } from 'react';
import axios from 'axios';
import Toolbar from './components/Toolbar.jsx';
import Editor from './components/Editor.jsx';
import CompilerSources from './components/CompilerSources.jsx';
import CompilerOverview from './components/CompilerOverview.jsx';

const defaultCode = `void main(void) {
    int x;
    x = 5;
    output(x);
}`;

function App() {
  const [code, setCode] = useState(defaultCode);
  const [tmCode, setTmCode] = useState('');
  const [compileOut, setCompileOut] = useState('');
  const [runOut, setRunOut] = useState('');
  const [input, setInput] = useState('');
  const [loading, setLoading] = useState(false);

  const [showSources, setShowSources] = useState(false);
  const [showOverview, setShowOverview] = useState(false);
  const [sourceInitialId, setSourceInitialId] = useState('');

  const compile = async (andRun = false) => {
    setLoading(true);
    setCompileOut('Compilando...');
    if (!andRun) setRunOut('');
    try {
      const res = await axios.post('/api/compile', { code });
      setCompileOut(
        `success: ${res.data.success}\n\nstdout:\n${res.data.stdout}\n\nstderr:\n${res.data.stderr}`
      );
      setTmCode(res.data.tmCode || '');
      if (andRun && res.data.tmCode) {
        await run(res.data.tmCode, input, true);
      }
    } catch (e) {
      const msg =
        e.response?.data ? JSON.stringify(e.response.data, null, 2) : e.message;
      setCompileOut('Erro na requisição:\n' + msg);
    } finally {
      setLoading(false);
    }
  };

  const run = async (tm = tmCode, programInput = input, fromCompile = false) => {
    if (!tm) {
      if (!fromCompile) setRunOut('Compile primeiro para gerar o TM.');
      return;
    }
    if (!fromCompile) setRunOut('Executando...');
    try {
      const res = await axios.post('/api/run', {
        tmCode: tm,
        input: programInput
      });
      setRunOut(
        `success: ${res.data.success}\n\noutput:\n${res.data.output}\n\nerrors:\n${res.data.errors}`
      );
    } catch (e) {
      const msg =
        e.response?.data ? JSON.stringify(e.response.data, null, 2) : e.message;
      setRunOut('Erro na requisição:\n' + msg);
    }
  };

  return (
    <div className="app">
      <Toolbar
        onCompile={() => compile(false)}
        onRun={() => compile(true)}
        onShowSources={() => setShowSources(true)}
        onShowOverview={() => setShowOverview(true)}
        loading={loading}
      />

      <div className="main">
        {/* Coluna esquerda: editor + input */}
        <div className="main-left">
          <div className="card card-editor">
            <div className="card-header">
              <div className="card-title">Editor C-</div>
              <div className="card-subtitle">
                Digite e edite programas em C-; use os botões da toolbar para
                compilar e executar.
              </div>
            </div>
            <div className="card-body card-body-editor">
              <Editor value={code} onChange={setCode} />
            </div>
          </div>

          <div className="card card-input">
            <div className="card-header">
              <div className="card-title">Input do programa</div>
              <div className="card-subtitle">
                Uma linha por entrada lida por input(); valores são enviados
                para a TM.
              </div>
            </div>
            <div className="card-body">
              <textarea
                className="input"
                value={input}
                onChange={(e) => setInput(e.target.value)}
                placeholder="Uma linha por entrada (ex: 5)"
              />
            </div>
          </div>
        </div>

        {/* Coluna direita: saídas */}
        <div className="main-right">
          <div className="card">
            <div className="card-header">
              <div className="card-title">Saída da Compilação</div>
              <div className="card-subtitle">
                Mostra árvore sintática, tabela de símbolos, erros léxicos,
                sintáticos e semânticos, além de mensagens gerais do compilador.
              </div>
            </div>
            <div className="card-body">
              <pre className="output">{compileOut}</pre>
            </div>
          </div>

          <div className="card">
            <div className="card-header">
              <div className="card-title">Código TM</div>
              <div className="card-subtitle">
                Instruções geradas para a Tiny Machine, equivalentes ao código
                intermediário descrito na teoria.
              </div>
            </div>
            <div className="card-body">
              <pre className="output">
                {tmCode || 'Compile para gerar o TM...'}
              </pre>
            </div>
          </div>

          <div className="card">
            <div className="card-header">
              <div className="card-title">Saída da Execução</div>
              <div className="card-subtitle">
                Resultado da execução do programa na TM, incluindo prints e
                mensagens de erro.
              </div>
            </div>
            <div className="card-body">
              <pre className="output">{runOut}</pre>
            </div>
          </div>
        </div>
      </div>

      {/* Overlay: viewer de código do compilador */}
      {showSources && (
        <CompilerSources
          onClose={() => setShowSources(false)}
          initialId={sourceInitialId}
        />
      )}

      {/* Overlay: esquema visual do compilador */}
      {showOverview && (
        <CompilerOverview
          onClose={() => setShowOverview(false)}
          onSelectSource={(id) => {
            setSourceInitialId(id);
            setShowOverview(false);
            setShowSources(true);
          }}
        />
      )}
    </div>
  );
}

export default App;
