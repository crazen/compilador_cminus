#include "globals.h"
#include "symtab.h"
#include "cgen.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Registradores da TM */
#define AC 0
#define AC1 1
#define GP 5  /* Global Pointer */
#define MP 6  /* Memory Pointer (Stack) */
#define PC 7

static int tmpOffset = 0;
static int emitLoc = 0; 
static int highEmitLoc = 0; 

/* -- ESTRUTURAS PARA BACKPATCHING -- */
typedef struct FuncRec {
    char *name;
    int address;
    struct FuncRec *next;
} *FuncList;

typedef struct CallRec {
    int loc; 
    char *name;
    struct CallRec *next;
} *CallList;

static FuncList funcTable = NULL;
static CallList callList = NULL;

void addFunction(char *name, int addr) {
    FuncList f = (FuncList)malloc(sizeof(struct FuncRec));
    f->name = strdup(name);
    f->address = addr;
    f->next = funcTable;
    funcTable = f;
}

int getFunctionAddr(char *name) {
    FuncList f = funcTable;
    while(f != NULL) {
        if(strcmp(f->name, name)==0) return f->address;
        f = f->next;
    }
    return -1;
}

void addCallPatch(int loc, char *name) {
    CallList c = (CallList)malloc(sizeof(struct CallRec));
    c->loc = loc;
    c->name = strdup(name);
    c->next = callList;
    callList = c;
}

/* Funções de Emissão */
static void emitComment(char *c) { if (TraceCode) fprintf(code, "* %s\n", c); }

static void emitRO(char *op, int r, int s, int t, char *c) {
    fprintf(code, "%3d:  %5s  %d,%d,%d    %s\n", emitLoc++, op, r, s, t, c);
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

static void emitRM(char *op, int r, int d, int s, char *c) {
    fprintf(code, "%3d:  %5s  %d,%d(%d)    %s\n", emitLoc++, op, r, d, s, c);
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

static int emitSkip(int howMany) {
    int i = emitLoc;
    emitLoc += howMany;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
    return i;
}

static void emitBackup(int loc) { emitLoc = loc; }
static void emitRestore(void) { emitLoc = highEmitLoc; }

static void emitRM_Abs(char *op, int r, int a, char *c) {
    fprintf(code, "%3d:  %5s  %d,%d(%d)    %s\n", emitLoc, op, r, a - (emitLoc + 1), 7, c);
    ++emitLoc;
    if (highEmitLoc < emitLoc) highEmitLoc = emitLoc;
}

/* Gera Código */
void cGen(TreeNode *t) {
    int savedLoc1, savedLoc2, currentLoc;
    
    if (t == NULL) return;
    
    switch (t->nodekind) {
        case StmtK:
            switch (t->kind.stmt) {
                case FunDeclK:
                    emitComment("-> Inicio Funcao");
                    emitComment(t->attr.name);
                    addFunction(t->attr.name, emitLoc);
                    
                    /* Prólogo */
                    emitRM("ST", AC, -1, MP, "store return address");
                    
                    /* CORREÇÃO: Espaço maior para locais e temporários */
                    /* Se tmpOffset for muito pequeno, colide com locais */
                    tmpOffset = -20; 
                    
                    cGen(t->child[2]);
                    
                    /* Epílogo */
                    emitRM("LD", PC, -1, MP, "return to caller");
                    emitComment("<- Fim Funcao");
                    break;

                case ReturnK:
                    emitComment("-> Return");
                    cGen(t->child[0]); 
                    emitRM("LD", PC, -1, MP, "return to caller");
                    emitComment("<- Return");
                    break;

                case CallK:
                    emitComment("-> Chamada");
                    if (strcmp(t->attr.name, "input") == 0) {
                        emitRO("IN", AC, 0, 0, "read integer");
                    } else if (strcmp(t->attr.name, "output") == 0) {
                        cGen(t->child[0]);
                        emitRO("OUT", AC, 0, 0, "write integer");
                    } else {
                        /* --- CORREÇÃO DE ALINHAMENTO DE PILHA --- */
                        int frameBase = tmpOffset; /* O novo MP será aqui */
                        TreeNode *arg = t->child[0];
                        int argIdx = 0;
                        
                        /* Calcula e empilha argumentos */
                        while (arg != NULL) {
                            cGen(arg);
                            /* Salva argumento na posição relativa ao FUTURO MP */
                            /* Param 0 fica em -2(NewMP), Param 1 em -3(NewMP)... */
                            emitRM("ST", AC, frameBase - 2 - argIdx, MP, "push argument");
                            arg = arg->sibling;
                            argIdx++;
                        }
                        
                        /* Salva MP atual no início do novo frame (offset 0) */
                        emitRM("ST", MP, frameBase, MP, "store old MP"); 
                        
                        /* Move MP para o novo frame */
                        emitRM("LDA", MP, frameBase, MP, "push new frame");
                        
                        /* Prepara endereço de retorno */
                        emitRM("LDC", AC, emitLoc + 2, 0, "load return address");
                        
                        /* Pula */
                        int jumpLoc = emitSkip(1);
                        addCallPatch(jumpLoc, t->attr.name);
                        
                        /* Restaura MP */
                        emitRM("LD", MP, 0, MP, "pop frame");
                    }
                    emitComment("<- Chamada");
                    break;

                case CompoundK:
                    cGen(t->child[0]); 
                    cGen(t->child[1]);
                    break;

                case AssignK:
                    emitComment("-> Atrib");
                    cGen(t->child[1]);
                    if (t->child[0]->scope == 0) 
                        emitRM("ST", AC, t->child[0]->memloc, GP, "store global");
                    else 
                        emitRM("ST", AC, -(t->child[0]->memloc + 2), MP, "store local");
                    emitComment("<- Atrib");
                    break;

                case IfK:
                    emitComment("-> If");
                    cGen(t->child[0]);
                    savedLoc1 = emitSkip(1);
                    cGen(t->child[1]);
                    savedLoc2 = emitSkip(1);
                    currentLoc = emitSkip(0);
                    emitBackup(savedLoc1); emitRM_Abs("JEQ", AC, currentLoc, "if: jump false"); emitRestore();
                    cGen(t->child[2]);
                    currentLoc = emitSkip(0);
                    emitBackup(savedLoc2); emitRM_Abs("LDA", PC, currentLoc, "if: jump end"); emitRestore();
                    emitComment("<- If");
                    break;

                case WhileK:
                    emitComment("-> While");
                    savedLoc1 = emitSkip(0);
                    cGen(t->child[0]);
                    savedLoc2 = emitSkip(1);
                    cGen(t->child[1]);
                    emitRM_Abs("LDA", PC, savedLoc1, "while: loop");
                    currentLoc = emitSkip(0);
                    emitBackup(savedLoc2); emitRM_Abs("JEQ", AC, currentLoc, "while: exit"); emitRestore();
                    emitComment("<- While");
                    break;
                    
                default: break;
            }
            break;

        case ExpK:
            switch (t->kind.exp) {
                case ConstK:
                    emitRM("LDC", AC, t->attr.val, 0, "load const");
                    break;
                case IdK:
                    if (t->scope == 0) 
                        emitRM("LD", AC, t->memloc, GP, "load global");
                    else 
                        emitRM("LD", AC, -(t->memloc + 2), MP, "load local");
                    break;
                case OpK:
                    cGen(t->child[0]);
                    /* Usa tmpOffset para empilhar temporários da expressão */
                    emitRM("ST", AC, tmpOffset--, MP, "op: push left");
                    cGen(t->child[1]);
                    emitRM("LD", AC1, ++tmpOffset, MP, "op: load left");
                    switch (t->attr.op) {
                        case PLUS: emitRO("ADD", AC, AC1, AC, "op +"); break;
                        case MINUS: emitRO("SUB", AC, AC1, AC, "op -"); break;
                        case TIMES: emitRO("MUL", AC, AC1, AC, "op *"); break;
                        case OVER: emitRO("DIV", AC, AC1, AC, "op /"); break;
                        case LT: emitRO("SUB", AC, AC1, AC, "op <"); emitRM("JLT",AC,2,PC,"br true"); emitRM("LDC",AC,0,0,"false"); emitRM("LDA",PC,1,PC,"skip"); emitRM("LDC",AC,1,0,"true"); break;
                        default: emitRO("SUB", AC, AC1, AC, "op default"); break;
                    }
                    break;
                default: break;
            }
            break;
        default: break;
    }
    cGen(t->sibling);
}

void performBackpatch() {
    CallList c = callList;
    while (c != NULL) {
        int addr = getFunctionAddr(c->name);
        if (addr == -1) {
            printf("Erro Linker: Funcao '%s' nao encontrada.\n", c->name);
        } else {
            int savedLoc = emitLoc;
            emitBackup(c->loc);
            fprintf(code, "%3d:  %5s  %d,%d(%d)    %s\n", c->loc, "LDC", PC, addr, 0, "jump to func");
            emitBackup(savedLoc);
        }
        c = c->next;
    }
}

void codeGen(TreeNode *syntaxTree, char *codefile) {
    fprintf(code, "* C-Minus to TM Code (Stack Machine)\n");
    fprintf(code, "* File: %s\n", codefile);
    
    /* Inicialização Segura */
    emitRM("LDC", MP, 1023, 0, "initialize Stack Pointer"); 
    emitRM("LDC", GP, 0, 0, "initialize Global Pointer");
    emitRM("ST",  0, 0, 0, "clear location 0");
    
    /* Endereço de retorno da main para HALT */
    emitRM("LDC", AC, emitLoc + 2, 0, "load main return addr");
    
    int mainJumpLoc = emitSkip(1);
    
    emitRO("HALT", 0, 0, 0, "END OF PROGRAM");
    
    cGen(syntaxTree);
    
    int mainAddr = getFunctionAddr("main");
    int saved = emitLoc;
    emitBackup(mainJumpLoc);
    fprintf(code, "%3d:  %5s  %d,%d(%d)    %s\n", mainJumpLoc, "LDC", PC, mainAddr, 0, "jump to main");
    emitBackup(saved);
    
    performBackpatch();
    
    printf("Código Stack-Machine gerado em %s\n", codefile);
}