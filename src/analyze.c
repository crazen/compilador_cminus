#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "ast.h"

static int location = 0;
static int currentScope = 0; /* 0 = Global, 1 = Local */

static void traverse(TreeNode *t,
                     void (*preProc)(TreeNode*),
                     void (*postProc)(TreeNode*)) {
    if (t != NULL) {
        int enterScope = 0;

        if (preProc != NULL) preProc(t);

        if (t->nodekind == StmtK && t->kind.stmt == FunDeclK) {
            if (t->attr.name != NULL) scope_push(t->attr.name);
            else scope_push("func");
            enterScope = 1;
            location = 0; 
            currentScope = 1; /* Entrou em função -> Local */
        }

        int i;
        for (i=0; i < MAXCHILDREN; i++)
            traverse(t->child[i], preProc, postProc);

        if (enterScope) {
            scope_pop();
            currentScope = 0; /* Saiu da função -> Global */
        }

        if (postProc != NULL) postProc(t);
        traverse(t->sibling, preProc, postProc);
    }
}

static void insertNode(TreeNode *t) {
    switch (t->nodekind) {
        case StmtK:
            switch (t->kind.stmt) {
                case VarDeclK:
                case ParamK: 
                    t->memloc = location++;
                    t->scope = currentScope; /* Salva o escopo */
                    st_insert(t->attr.name, t->lineno, t->memloc, t);
                    break;
                case FunDeclK:
                    st_insert(t->attr.name, t->lineno, 0, t);
                    break;
                case CallK:
                    if (strcmp(t->attr.name, "input") == 0) t->type = Integer;
                    else if (strcmp(t->attr.name, "output") == 0) t->type = Void;
                    else {
                        TreeNode *funcDef = st_lookup(t->attr.name);
                        if (funcDef != NULL) t->type = funcDef->type;
                        else t->type = Void;
                    }
                    break;
                default: break;
            }
            break;
        case ExpK:
            if (t->kind.exp == IdK) {
                TreeNode *defn = st_lookup(t->attr.name);
                if (defn != NULL) {
                    t->memloc = defn->memloc;
                    t->type = defn->type;
                    t->scope = defn->scope; /* Copia o escopo para o uso */
                }
            } else if (t->kind.exp == ConstK || t->kind.exp == OpK) {
                t->type = Integer;
            }
            break;
        default: break;
    }
}

void buildSymtab(TreeNode *syntaxTree) {
    location = 0; 
    currentScope = 0;
    scope_push("global");
    traverse(syntaxTree, insertNode, NULL);
    if (TraceAnalyze) printSymTab(listing);
    scope_pop();
}

static void checkNode(TreeNode *t) { (void)t; }

void typeCheck(TreeNode *syntaxTree) {
    traverse(syntaxTree, NULL, checkNode);
}