%code requires {
    #include "globals.h"
    #include "ast.h"
    #define YYSTYPE TreeNode *
}

%{
#define _POSIX_C_SOURCE 200809L
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "symtab.h" 

static char savedName[120]; 
static char savedID[120]; /* Buffer para salvar IDs de arrays/params */
static int savedNum;
static TreeNode *savedTree; 

int yylex(void);
void yyerror(char *message);
%}

%token IF ELSE INT RETURN VOID WHILE INPUT OUTPUT
%token ID NUM 
%token ASSIGN EQ NE LT LE GT GE PLUS MINUS TIMES OVER
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI COMMA
%token ERROR

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

programa
    : declaration_list                  { savedTree = $1; }
    ;

declaration_list
    : declaration_list declaration      {
                                          YYSTYPE t = $1;
                                          if (t != NULL) {
                                              while (t->sibling != NULL)
                                                  t = t->sibling;
                                              t->sibling = $2;
                                              $$ = $1;
                                          } else $$ = $2;
                                        }
    | declaration                       { $$ = $1; }
    ;

declaration
    : var_declaration                   { $$ = $1; }
    | fun_declaration                   { $$ = $1; }
    ;

/* --- DECLARAÇÃO DE VARIÁVEIS --- */
var_declaration
    : type_specifier ID SEMI             {
                                          $$ = newStmtNode(VarDeclK);
                                          $$->attr.name = strdup(tokenString); 
                                          $$->type = ($1->attr.name[0]=='i') ? Integer : Void;
                                          $$->child[0] = $1;
                                        }
    | type_specifier ID 
      { strcpy(savedID, tokenString); } /* Salva o nome do vetor aqui */
      LBRACK NUM 
      { savedNum = atoi(tokenString); } 
      RBRACK SEMI 
                                        {
                                          $$ = newStmtNode(VarDeclK);
                                          $$->attr.name = strdup(savedID); /* Usa o nome salvo */
                                          $$->type = Integer;
                                          $$->child[0] = $1;
                                          $$->child[1] = newExpNode(ConstK);
                                          $$->child[1]->attr.val = savedNum;
                                        }
    ;

type_specifier
    : INT                               { $$ = newExpNode(TypeK); $$->attr.name = "int"; }
    | VOID                              { $$ = newExpNode(TypeK); $$->attr.name = "void"; }
    ;

/* --- DECLARAÇÃO DE FUNÇÕES --- */
fun_declaration
    : type_specifier ID                 {
                                          strcpy(savedName, tokenString);
                                        }
      LPAREN params RPAREN compound_stmt {
                                          $$ = newStmtNode(FunDeclK);
                                          $$->attr.name = strdup(savedName);
                                          $$->type = ($1->attr.name[0]=='i') ? Integer : Void;
                                          $$->child[0] = $1;
                                          $$->child[1] = $5;
                                          $$->child[2] = $7;
                                        }
    ;

params
    : param_list                        { $$ = $1; }
    | VOID                              { $$ = NULL; }
    ;

param_list
    : param_list COMMA param            {
                                          YYSTYPE t = $1;
                                          while (t->sibling) t = t->sibling;
                                          t->sibling = $3;
                                          $$ = $1;
                                        }
    | param                             { $$ = $1; }
    ;

/* CORREÇÃO EM PARAMETROS: Salvar ID antes dos colchetes */
param
    : INT ID                            {
                                          $$ = newStmtNode(ParamK);
                                          $$->attr.name = strdup(tokenString);
                                          $$->type = Integer;
                                          $$->child[0] = newExpNode(TypeK); $$->child[0]->attr.name = "int";
                                        }
    | INT ID 
      { strcpy(savedID, tokenString); } /* Salva ID do array param */
      LBRACK RBRACK              
      {
          $$ = newStmtNode(ParamK);
          $$->attr.name = strdup(savedID); /* Usa o nome correto */
          $$->type = Integer;
          $$->child[0] = newExpNode(TypeK); $$->child[0]->attr.name = "int";
      }
    | VOID ID                           {
                                          $$ = newStmtNode(ParamK);
                                          $$->attr.name = strdup(tokenString);
                                          $$->type = Void;
                                          $$->child[0] = newExpNode(TypeK); $$->child[0]->attr.name = "void";
                                        }
    /* Caso raro void arr[] */
    | VOID ID LBRACK RBRACK             {
                                          $$ = newStmtNode(ParamK);
                                          /* Neste caso tokenString é RBRACK e perdemos o ID.
                                             Mas void array é inválido de qualquer forma. 
                                             Deixamos genérico. */
                                          $$->attr.name = "void_arr";
                                          $$->type = Void;
                                          $$->child[0] = newExpNode(TypeK); $$->child[0]->attr.name = "void";
                                        }
    ;

compound_stmt
    : LBRACE { scope_push("local"); } local_declarations statement_list RBRACE {
                                          scope_pop();
                                          $$ = newStmtNode(CompoundK);
                                          $$->child[0] = $3;
                                          $$->child[1] = $4;
                                        }
    ;

local_declarations
    : local_declarations var_declaration {
                                          YYSTYPE t = $1;
                                          if (t != NULL) {
                                              while (t->sibling) t = t->sibling;
                                              t->sibling = $2;
                                              $$ = $1;
                                          } else $$ = $2;
                                        }
    | /* vazio */                        { $$ = NULL; }
    ;

statement_list
    : statement_list statement          {
                                          YYSTYPE t = $1;
                                          if (t != NULL) {
                                              while (t->sibling) t = t->sibling;
                                              t->sibling = $2;
                                              $$ = $1;
                                          } else $$ = $2;
                                        }
    | /* vazio */                        { $$ = NULL; }
    ;

statement
    : expression_stmt                   { $$ = $1; }
    | compound_stmt                     { $$ = $1; }
    | selection_stmt                    { $$ = $1; }
    | iteration_stmt                    { $$ = $1; }
    | return_stmt                       { $$ = $1; }
    | input_stmt                        { $$ = $1; }
    | output_stmt                       { $$ = $1; }
    ;

expression_stmt
    : expression SEMI                   { $$ = $1; }
    | SEMI                              { $$ = NULL; }
    ;

selection_stmt
    : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
                                        { $$ = newStmtNode(IfK); $$->child[0] = $3; $$->child[1] = $5; }
    | IF LPAREN expression RPAREN statement ELSE statement
                                        { $$ = newStmtNode(IfK); $$->child[0] = $3; $$->child[1] = $5; $$->child[2] = $7; }
    ;

iteration_stmt
    : WHILE LPAREN expression RPAREN statement
                                        { $$ = newStmtNode(WhileK); $$->child[0] = $3; $$->child[1] = $5; }
    ;

return_stmt
    : RETURN SEMI                       { $$ = newStmtNode(ReturnK); }
    | RETURN expression SEMI            { $$ = newStmtNode(ReturnK); $$->child[0] = $2; }
    ;

input_stmt
    : INPUT LPAREN ID RPAREN SEMI       {
                                          $$ = newStmtNode(CallK);
                                          $$->attr.name = "input";
                                          TreeNode *arg = newExpNode(IdK);
                                          arg->attr.name = strdup(tokenString);
                                          $$->child[0] = arg;
                                        }
    ;

output_stmt
    : OUTPUT LPAREN expression RPAREN SEMI
                                        {
                                          $$ = newStmtNode(CallK);
                                          $$->attr.name = "output";
                                          $$->child[0] = $3;
                                        }
    ;

expression
    : var ASSIGN expression             { $$ = newStmtNode(AssignK); $$->child[0] = $1; $$->child[1] = $3; }
    | simple_expression                 { $$ = $1; }
    ;

/* CORREÇÃO EM USO DE ARRAY: Salvar ID antes dos colchetes */
var
    : ID                                { $$ = newExpNode(IdK); $$->attr.name = strdup(tokenString); }
    | ID 
      { strcpy(savedID, tokenString); } /* Salva ID do array */
      LBRACK expression RBRACK       
      {
          $$ = newExpNode(IdK);
          $$->attr.name = strdup(savedID); /* Usa nome salvo */
          $$->child[0] = $3; /* child[0] é o índice */
      }
    ;

simple_expression
    : additive_expression relop additive_expression
                                        { $$ = $2; $$->child[0] = $1; $$->child[1] = $3; }
    | additive_expression               { $$ = $1; }
    ;

relop
    : LE                                { $$ = newExpNode(OpK); $$->attr.op = LE; }
    | LT                                { $$ = newExpNode(OpK); $$->attr.op = LT; }
    | GT                                { $$ = newExpNode(OpK); $$->attr.op = GT; }
    | GE                                { $$ = newExpNode(OpK); $$->attr.op = GE; }
    | EQ                                { $$ = newExpNode(OpK); $$->attr.op = EQ; }
    | NE                                { $$ = newExpNode(OpK); $$->attr.op = NE; }
    ;

additive_expression
    : additive_expression addop term    { $$ = $2; $$->child[0] = $1; $$->child[1] = $3; }
    | term                              { $$ = $1; }
    ;

addop
    : PLUS                              { $$ = newExpNode(OpK); $$->attr.op = PLUS; }
    | MINUS                             { $$ = newExpNode(OpK); $$->attr.op = MINUS; }
    ;

term
    : term mulop factor                 { $$ = $2; $$->child[0] = $1; $$->child[1] = $3; }
    | factor                            { $$ = $1; }
    ;

mulop
    : TIMES                             { $$ = newExpNode(OpK); $$->attr.op = TIMES; }
    | OVER                              { $$ = newExpNode(OpK); $$->attr.op = OVER; }
    ;

factor
    : LPAREN expression RPAREN          { $$ = $2; }
    | var                               { $$ = $1; }
    | call                              { $$ = $1; }
    | NUM                               { $$ = newExpNode(ConstK); $$->attr.val = atoi(tokenString); }
    | INPUT LPAREN RPAREN               {
                                          $$ = newStmtNode(CallK);
                                          $$->attr.name = "input";
                                        }
    ;

call
    : ID 
      { strcpy(savedID, tokenString); } 
      LPAREN args RPAREN             
      {
          $$ = newStmtNode(CallK);
          $$->attr.name = strdup(savedID);
          $$->child[0] = $4;
      }
    ;

args
    : arg_list                          { $$ = $1; }
    | /* vazio */                        { $$ = NULL; }
    ;

arg_list
    : arg_list COMMA expression         {
                                          YYSTYPE t = $1;
                                          while (t->sibling) t = t->sibling;
                                          t->sibling = $3;
                                          $$ = $1;
                                        }
    | expression                        { $$ = $1; }
    ;

%%

void yyerror(char *message) {
    fprintf(listing, "ERRO SINTATICO: %s na linha %d\n", message, lineno);
    Error = TRUE;
}

TreeNode *parse(void) {
    yyparse();
    return savedTree;
}