import { Play, Zap, Trash2, FileCode, Workflow } from 'lucide-react';

export default function Toolbar({
  onCompile,
  onRun,
  onShowSources,
  onShowOverview,
  loading
}) {
  return (
    <div className="toolbar">
      <div className="toolbar-left">
        <h1>Compilador C-</h1>
      </div>
      <div className="toolbar-right">
        <button className="btn" onClick={onShowOverview}>
          <Workflow size={16} />
          Fluxo do compilador
        </button>
        <button className="btn" onClick={onShowSources}>
          <FileCode size={16} />
          Código do compilador
        </button>
        <button className="btn" onClick={onCompile} disabled={loading}>
          <Play size={16} />
          {loading ? 'Compilando...' : 'Compilar'}
        </button>
        <button className="btn" onClick={onRun} disabled={loading}>
          <Zap size={16} />
          Compilar e Executar
        </button>
        <button className="btn" onClick={() => window.location.reload()}>
          <Trash2 size={16} />
          Resetar
        </button>
      </div>
    </div>
  );
}
