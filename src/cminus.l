%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

char tokenString[256];

void copyTokenString() {
    strncpy(tokenString, yytext, 255);
    tokenString[255] = '\0'; 
}
%}

%option noyywrap

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}({letter}|{digit})*
newline     \n
/* CORREÇÃO AQUI: Adicionado \r para suportar arquivos Windows */
whitespace  [ \t\r]+

%%

"if"         { return IF; }
"else"       { return ELSE; }
"int"        { return INT; }
"return"     { return RETURN; }
"void"       { return VOID; }
"while"      { return WHILE; }
"input"      { return INPUT; }
"output"     { return OUTPUT; }

"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return TIMES; }
"/"          { return OVER; }
"<"          { return LT; }
"<="         { return LE; }
">"          { return GT; }
">="         { return GE; }
"=="         { return EQ; }
"!="         { return NE; }
"="          { return ASSIGN; }
";"          { return SEMI; }
","          { return COMMA; }
"("          { return LPAREN; }
")"          { return RPAREN; }
"["          { return LBRACK; }
"]"          { return RBRACK; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }

{number}     { copyTokenString(); return NUM; }
{identifier} { copyTokenString(); return ID; }
{newline}    { lineno++; }
{whitespace} { /* ignora */ }

"/*" {
    int c;
    while (1) {
        c = input();
        if (c == EOF) break;
        if (c == '\n') lineno++;
        if (c == '*') {
            if ((c = input()) == '/') break;
        }
    }
}

. {
    fprintf(listing,"ERRO LEXICO: '%s' - LINHA: %d\n", yytext, lineno);
    Error = TRUE;
}

%%

TokenType getToken(void) {
    static int firstTime = TRUE;
    TokenType currentToken;
    if (firstTime) {
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
    }
    currentToken = yylex();
    if(currentToken != ID && currentToken != NUM) {
        strncpy(tokenString, yytext, 255);
    }
    
    if (TraceScan) {
        fprintf(listing,"%-15s %d\n", yytext, currentToken);
    }
    return currentToken;
}