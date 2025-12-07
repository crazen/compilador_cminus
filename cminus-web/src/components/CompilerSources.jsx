import { useEffect, useState } from 'react';
import axios from 'axios';
import { FileText } from 'lucide-react';
import { Editor as MonacoEditor } from '@monaco-editor/react';

export default function CompilerSources({ onClose, initialId }) {
  const [files, setFiles] = useState([]);
  const [selectedId, setSelectedId] = useState(initialId || '');
  const [content, setContent] = useState('');
  const [loadingList, setLoadingList] = useState(false);
  const [loadingFile, setLoadingFile] = useState(false);

  // Carrega lista de arquivos
  useEffect(() => {
    const loadFiles = async () => {
      setLoadingList(true);
      try {
        const res = await axios.get('/api/sources');
        setFiles(res.data);
        if (!selectedId && res.data.length > 0) {
          setSelectedId(res.data[0].id);
        }
      } catch (e) {
        console.error('Erro carregando lista de fontes', e);
      } finally {
        setLoadingList(false);
      }
    };
    loadFiles();
  }, []); // selectedId é controlado por estado

  // Carrega conteúdo do arquivo selecionado
  useEffect(() => {
    if (!selectedId) return;
    const loadFile = async () => {
      setLoadingFile(true);
      try {
        const res = await axios.get(`/api/sources/${encodeURIComponent(selectedId)}`);
        setContent(res.data.content || '');
      } catch (e) {
        console.error('Erro carregando fonte', e);
        setContent('// Erro ao carregar arquivo');
      } finally {
        setLoadingFile(false);
      }
    };
    loadFile();
  }, [selectedId]);

  return (
    <div
      style={{
        position: 'fixed',
        inset: 0,
        background: 'rgba(15,23,42,0.97)',
        zIndex: 60,
        display: 'flex',
        flexDirection: 'column'
      }}
    >
      {/* Cabeçalho alinhado com o resto da app */}
      <div
        style={{
          padding: '12px 28px',
          borderBottom: '1px solid #1f2937',
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'space-between',
          background: '#020617'
        }}
      >
        <div
          style={{
            fontFamily:
              'JetBrains Mono, ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, Liberation Mono, Courier New, monospace',
            fontSize: 18,
            fontWeight: 600,
            color: '#f9fafb',
            letterSpacing: 0.06
          }}
        >
          Código do compilador C-
        </div>
        <button
          className="btn"
          onClick={onClose}
          style={{ paddingInline: 16, fontSize: 13 }}
        >
          Fechar
        </button>
      </div>

      {/* Corpo: sidebar + editor, usando flexbox */}
      <div
        style={{
          flex: 1,
          display: 'flex',
          minHeight: 0,
          padding: '16px 24px 20px',
          gap: 16
        }}
      >
        {/* Lista de arquivos */}
        <div
          style={{
            width: 260,
            minWidth: 220,
            maxWidth: 280,
            background: '#020617',
            borderRadius: 10,
            border: '1px solid #1f2937',
            boxShadow: '0 10px 30px rgba(15,23,42,0.7)',
            display: 'flex',
            flexDirection: 'column',
            overflow: 'hidden'
          }}
        >
          <div
            style={{
              padding: '10px 12px',
              borderBottom: '1px solid #1f2937',
              fontSize: 13,
              fontWeight: 500,
              color: '#e5e7eb'
            }}
          >
            Arquivos fonte
          </div>
          <div
            style={{
              flex: 1,
              overflowY: 'auto',
              padding: 6,
              fontSize: 13
            }}
          >
            {loadingList && <div style={{ padding: 6 }}>Carregando arquivos...</div>}
            {!loadingList &&
              files.map((f) => (
                <button
                  key={f.id}
                  onClick={() => setSelectedId(f.id)}
                  style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: 8,
                    width: '100%',
                    padding: '6px 8px',
                    marginBottom: 2,
                    borderRadius: 6,
                    border: 'none',
                    background:
                      f.id === selectedId
                        ? 'rgba(56,189,248,0.18)'
                        : 'transparent',
                    color: '#e5e7eb',
                    cursor: 'pointer',
                    textAlign: 'left',
                    fontSize: 13
                  }}
                >
                  <FileText size={15} />
                  <span
                    style={{
                      whiteSpace: 'nowrap',
                      textOverflow: 'ellipsis',
                      overflow: 'hidden'
                    }}
                  >
                    {f.id}
                  </span>
                </button>
              ))}
          </div>
        </div>

        {/* Editor Monaco com mesma vibe do resto */}
        <div
          style={{
            flex: 1,
            minWidth: 0,
            background: '#020617',
            borderRadius: 10,
            border: '1px solid #1f2937',
            boxShadow: '0 10px 30px rgba(15,23,42,0.7)',
            display: 'flex',
            flexDirection: 'column',
            overflow: 'hidden'
          }}
        >
          <div
            style={{
              padding: '8px 12px',
              borderBottom: '1px solid #1f2937',
              fontSize: 13,
              color: '#9ca3af',
              display: 'flex',
              justifyContent: 'space-between'
            }}
          >
            <span>{selectedId || 'Selecione um arquivo'}</span>
          </div>
          <div style={{ flex: 1, minHeight: 0 }}>
            {loadingFile && (
              <div style={{ padding: 10, fontSize: 13 }}>Carregando arquivo...</div>
            )}
            {!loadingFile && (
              <MonacoEditor
                height="100%"
                language="c"
                theme="vs-dark"
                value={content}
                onChange={() => {}}
                options={{
                  readOnly: true,
                  fontSize: 13,
                  minimap: { enabled: false },
                  scrollBeyondLastLine: false,
                  automaticLayout: true,
                  wordWrap: 'off',
                  lineNumbers: 'on',
                  fontFamily:
                    'JetBrains Mono, ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, Liberation Mono, Courier New, monospace'
                }}
              />
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
