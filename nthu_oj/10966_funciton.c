#include "10966_function.h"
#include <stdio.h>
#include <string.h>
BTNode* makeNode(char c){
    BTNode* new_node = (BTNode*) malloc(sizeof(BTNode));
    for (int i = 0; i < NUMSYM; i++) {
        if (c == sym[i]) new_node->data = i;
    }
    new_node->left = new_node->right = NULL;

    return new_node;
}
BTNode* EXPR() {
    BTNode* right_expr = FACTOR();
    // If a left parenthesis is encountered, or if we've hit the end of the input, 
    // then the expression we just computed has to be a left expression instead. 
    // So return it immediately.
    if (pos == -1 || expr[pos] == '(') return right_expr;
    BTNode* head = makeNode(expr[pos--]); // An operator is always expected here.
    head->right = right_expr;
    head->left = EXPR();
    return head;
}
BTNode* FACTOR() {
    char input = expr[pos--];
    BTNode* factorized;
    switch (input) {
        case ')': {
            factorized = EXPR();
            // A '(' (left parenthesis) is always expected after a factorized expression, so we skip it.
            pos--; 
            return factorized;
        }
        default:
            return makeNode(input);
    }
}