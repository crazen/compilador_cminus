/* util.h */
#ifndef _UTIL_H_
#define _UTIL_H_

#include "globals.h"
#include "ast.h"

void printToken(TokenType token, const char* tokenString);

TreeNode* newStmtNode(StmtKind kind);
TreeNode* newExpNode(ExpKind kind);
void printTree(TreeNode* tree, int level, int siblingNum);

#endif