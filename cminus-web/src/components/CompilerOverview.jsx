import { FileText, ArrowRight } from 'lucide-react';

export default function CompilerOverview({ onClose, onSelectSource }) {
  const phases = [
    {
      id: 'src/cminus.l',
      title: 'Análise Léxica',
      subtitle: 'Scanner (Flex)',
      desc: 'Transforma o texto bruto em tokens. Usa expressões regulares para identificar palavras-chave, identificadores, números e operadores. A função getToken() chama yylex() gerada pelo Flex e gerencia tokenString para uso posterior na AST.'
    },
    {
      id: 'src/cminus.y',
      title: 'Análise Sintática',
      subtitle: 'Parser (Bison)',
      desc: 'Organiza os tokens em uma Árvore Sintática Abstrata (AST) seguindo a Gramática Livre de Contexto. Resolve conflitos shift/reduce (ex: params -> VOID vs param -> INT ID) e usa ações de meio de regra (savedID, savedNum) para capturar nomes de variáveis e tamanhos de arrays antes de processar tokens subsequentes.'
    },
    {
      id: 'src/analyze.c',
      title: 'Análise Semântica',
      subtitle: 'Passadas 1 e 2',
      desc: 'Conecta a AST com a Tabela de Símbolos em duas etapas. Passada 1 (buildSymtab): popula a tabela, gerencia escopos (scope_push/pop), anota tipos e propaga informações de escopo (global/local) para os nós. Passada 2 (typeCheck): valida tipagem de operações, condições e atribuições, reportando erros semânticos.'
    },
    {
      id: 'src/cgen.c',
      title: 'Geração de Código',
      subtitle: 'Assembly TM',
      desc: 'Traduz a AST anotada para instruções Assembly da Tiny Machine usando estratégia de Máquina de Pilha. Gerencia registradores GP (globais) e MP (stack frame local). Implementa backpatching para resolver endereços de chamadas de função que ainda não foram compiladas. Usa tmpOffset para empilhar resultados parciais em expressões complexas.'
    },
    {
      id: 'tm.c',
      title: 'Execução',
      subtitle: 'Tiny Machine',
      desc: 'Simula o hardware da TM. Carrega o arquivo .tm na memória de instruções (iMem), executa o ciclo Fetch-Decode-Execute, simula 8 registradores e memória de dados (dMem), e processa instruções (LD, ST, ADD, SUB, IN, OUT, JLT, etc.) conforme especificado no material de apoio.'
    }
  ];

  const handleOpenSource = (fileId) => {
    if (onSelectSource) {
      onSelectSource(fileId);
    }
  };

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
            maxWidth: 1100,
            padding: '24px 28px 32px',
            display: 'flex',
            flexDirection: 'column',
            gap: 16
          }}
        >
          <div style={{ fontSize: 15, color: '#cbd5f5', lineHeight: 1.6 }}>
            Visão geral das fases do compilador: análise léxica, sintática e
            semântica, seguida da geração de código intermediário e execução na
            Tiny Machine (TM).
          </div>

          {/* Timeline de fases */}
          <div
            style={{
              display: 'flex',
              flexDirection: 'column',
              gap: 14,
              marginTop: 8
            }}
          >
            {phases.map((phase, idx) => (
              <div key={phase.id}>
                <div
                  style={{
                    background: '#020617',
                    borderRadius: 10,
                    border: '1px solid #1f2937',
                    boxShadow: '0 10px 30px rgba(15,23,42,0.7)',
                    padding: '16px 18px',
                    display: 'flex',
                    flexDirection: 'column',
                    gap: 10
                  }}
                >
                  {/* Header da fase */}
                  <div
                    style={{
                      display: 'flex',
                      alignItems: 'center',
                      justifyContent: 'space-between'
                    }}
                  >
                    <div style={{ display: 'flex', alignItems: 'center', gap: 10 }}>
                      <div
                        style={{
                          width: 32,
                          height: 32,
                          borderRadius: 6,
                          background: 'rgba(56,189,248,0.15)',
                          display: 'flex',
                          alignItems: 'center',
                          justifyContent: 'center',
                          fontSize: 15,
                          fontWeight: 700,
                          color: '#38bdf8'
                        }}
                      >
                        {idx + 1}
                      </div>
                      <div>
                        <div
                          style={{
                            fontSize: 16,
                            fontWeight: 600,
                            color: '#f9fafb'
                          }}
                        >
                          {phase.title}
                        </div>
                        <div style={{ fontSize: 13, color: '#9ca3af' }}>
                          {phase.subtitle}
                        </div>
                      </div>
                    </div>
                    {phase.id !== 'tm.c' && (
                      <button
                        className="btn"
                        onClick={() => handleOpenSource(phase.id)}
                        style={{
                          paddingInline: 14,
                          paddingBlock: 6,
                          fontSize: 12
                        }}
                      >
                        <FileText size={14} />
                        Ver código
                      </button>
                    )}
                  </div>

                  {/* Descrição da fase */}
                  <div
                    style={{
                      fontSize: 15.5,
                      color: '#cbd5e1',
                      lineHeight: 1.65
                    }}
                  >
                    {phase.desc}
                  </div>
                </div>

                {/* Seta entre fases */}
                {idx < phases.length - 1 && (
                  <div
                    style={{
                      display: 'flex',
                      justifyContent: 'center',
                      padding: '6px 0'
                    }}
                  >
                    <ArrowRight
                      size={20}
                      style={{
                        color: '#475569',
                        transform: 'rotate(90deg)'
                      }}
                    />
                  </div>
                )}
              </div>
            ))}
          </div>

          {/* Seção adicional: Pipeline */}
          <div
            style={{
              marginTop: 12,
              padding: '14px 16px',
              background: 'rgba(56,189,248,0.08)',
              borderRadius: 8,
              border: '1px solid rgba(56,189,248,0.2)',
              fontSize: 15,
              color: '#cbd5e1',
              lineHeight: 1.65
            }}
          >
            <strong style={{ color: '#f9fafb' }}>Pipeline Sequencial:</strong> O
            compilador opera em fases conectadas. Cada fase depende da anterior:
            a AST produzida pelo parser alimenta a análise semântica, que anota
            tipos e escopos usados pelo gerador de código. A estratégia de{' '}
            <strong>backpatching</strong> resolve endereços de funções em uma
            única passada, enquanto a <strong>Máquina de Pilha</strong> suporta
            recursão e expressões aninhadas.
          </div>
        </div>
      </div>
    </div>
  );
}
