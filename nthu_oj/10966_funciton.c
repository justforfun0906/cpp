#include "function.h"
#include <stdio.h>
#include <string.h>
BTNode* makeNode(char c){
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}
BTNode* EXPR(){
    BTNode *node = TERM();
    while (expr[pos] == '|' || expr[pos] == '&'){
        char op = expr[pos];
        pos--;
        BTNode *right = EXPR();
        BTNode *left = EXPR();
        node = makeNode(op);
        node->left = left;
        node->right = right;
    }
    return node;
}
BTNode* TERM(){
    BTNode *node = FACTOR();
    if (expr[pos] == '|' || expr[pos] == '&'){
        char op = expr[pos];
        pos--;
        BTNode *right = TERM();
        BTNode *left = TERM();
        node = makeNode(op);
        node->left = left;
        node->right = right;
    }
    return node;
}