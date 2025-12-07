import { ChevronRight } from 'lucide-react';

const STEPS = [
  {
    id: 'src/cminus.l',
    title: 'Scanner (Léxico)',
    subtitle: 'Análise léxica',
    description:
      'Lê o código C-, ignora espaços/comentários e converte o texto em tokens com informação de linha.'
  },
  {
    id: 'src/cminus.y',
    title: 'Parser (Sintático) + AST',
    subtitle: 'Análise sintática',
    description:
      'Consome os tokens e verifica se o programa segue a gramática da linguagem, construindo a Árvore Sintática Abstrata (AST).'
  },
  {
    id: 'include/symtab.h',
    title: 'Tabela de Símbolos',
    subtitle: 'Base para análise semântica',
    description:
      'Registra identificadores, tipos e escopos, servindo como estrutura central para as verificações semânticas.'
  },
  {
    id: 'src/analyze.c',
    title: 'Analisador Semântico',
    subtitle: 'Análise semântica',
    description:
      'Percorre a AST e a tabela de símbolos para detectar usos incorretos de variáveis, tipos incompatíveis e violações de regras da linguagem.'
  },
  {
    id: 'src/cgen.c',
    title: 'Geração de Código TM',
    subtitle: 'Síntese / código intermediário',
    description:
      'Transforma a AST em uma forma linear de instruções para a Tiny Machine (TM), próxima do código de três endereços discutido em aula.'
  },
  {
    id: 'tm',
    title: 'Máquina TM',
    subtitle: 'Execução',
    description:
      'Interpreta o código TM gerado, lê os inputs do usuário e produz a saída exibida no painel “Saída da Execução”.'
  }
];

export default function CompilerOverview({ onClose, onSelectSource }) {
  return (
    <div
      style={{
        position: 'fixed',
        inset: 0,
        background: 'rgba(15,23,42,0.97)',
        zIndex: 50,
        display: 'flex',
        flexDirection: 'column'
      }}
    >
      {/* Cabeçalho */}
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
            fontSize: 20,
            fontWeight: 700,
            color: '#f9fafb',
            letterSpacing: 0.08
          }}
        >
          Fluxo do compilador C-
        </div>
        <button
          className="btn"
          onClick={onClose}
          style={{ paddingInline: 16, fontSize: 13 }}
        >
          Fechar
        </button>
      </div>

      {/* Conteúdo principal */}
      <div
        style={{
          flex: 1,
          display: 'flex',
          justifyContent: 'center',
          overflowY: 'auto'
        }}
      >
        <div
          style={{
            width: '100%',
            maxWidth: 980,
            padding: '26px 26px 34px',
            display: 'flex',
            flexDirection: 'column',
            gap: 24
          }}
        >
          <div style={{ fontSize: 15, color: '#cbd5f5' }}>
            Visão geral das fases do compilador: análise léxica, sintática e semântica,
            seguida da geração de código intermediário e execução na Tiny Machine (TM).
          </div>

          {/* Timeline vertical */}
          <div
            style={{
              position: 'relative',
              paddingLeft: 30,
              marginTop: 8
            }}
          >
            {/* Linha vertical */}
            <div
              style={{
                position: 'absolute',
                left: 16,
                top: 0,
                bottom: 0,
                width: 2,
                background:
                  'linear-gradient(to bottom, rgba(148,163,184,0.5), rgba(59,130,246,0.9))'
              }}
            />

            <div
              style={{
                display: 'flex',
                flexDirection: 'column',
                gap: 22
              }}
            >
              {STEPS.map((step, index) => (
                <div
                  key={step.title}
                  style={{
                    display: 'flex',
                    alignItems: 'flex-start',
                    gap: 18
                  }}
                >
                  {/* Nó circular */}
                  <div
                    style={{
                      position: 'relative',
                      marginTop: 10
                    }}
                  >
                    <div
                      style={{
                        height: 18,
                        width: 18,
                        borderRadius: '999px',
                        border: '2px solid #38bdf8',
                        background: '#020617',
                        boxShadow: '0 0 0 5px rgba(56,189,248,0.22)'
                      }}
                    />
                  </div>

                  {/* Card grande */}
                  <div
                    style={{
                      flex: 1,
                      background: '#020617',
                      borderRadius: 12,
                      border: '1px solid #1f2937',
                      padding: 16,
                      boxShadow: '0 14px 36px rgba(15,23,42,0.7)'
                    }}
                  >
                    <div
                      style={{
                        display: 'flex',
                        justifyContent: 'space-between',
                        alignItems: 'baseline',
                        marginBottom: 6
                      }}
                    >
                      <div
                        style={{
                          fontSize: 14,
                          fontWeight: 500,
                          color: '#9ca3af',
                          letterSpacing: 0.8
                        }}
                      >
                        {String(index + 1).padStart(2, '0')} · {step.subtitle}
                      </div>
                    </div>
                    <div
                      style={{
                        fontSize: 17,
                        fontWeight: 600,
                        color: '#f9fafb',
                        marginBottom: 6
                      }}
                    >
                      {step.title}
                    </div>
                    <div
                      style={{
                        fontSize: 14,
                        color: '#e5e7eb',
                        lineHeight: 1.6,
                        marginBottom: 12
                      }}
                    >
                      {step.description}
                    </div>

                    {step.id !== 'tm' && (
                      <button
                        className="btn"
                        style={{ padding: '4px 11px', fontSize: 12 }}
                        onClick={() => onSelectSource && onSelectSource(step.id)}
                      >
                        <ChevronRight size={14} />
                        Ver código relacionado
                      </button>
                    )}
                  </div>
                </div>
              ))}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
