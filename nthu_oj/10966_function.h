#ifndef FUNCTION_H
#define FUNCTION_H
#include<stdio.h>
#include<stdlib.h>
#define MAXEXPR 256
#define NUMSYM 6

extern char expr[MAXEXPR];  // string to store the input expression.
extern int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
extern char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

extern BTNode* EXPR();
extern BTNode* FACTOR();
extern BTNode* makeNode(char c);
void freeTree(BTNode *root);
extern void printPrefix(BTNode *root);
BTNode* makeNode(char c){// create a node to store the operator and operands
    BTNode* new_node = (BTNode*) malloc(sizeof(BTNode));
    for (int i = 0; i < NUMSYM; i++) {
        if (c == sym[i]) new_node->data = i;
    }
    new_node->left = new_node->right = NULL;
    return new_node;
}
BTNode* EXPR() {
    BTNode* right_node = FACTOR();
    //if encounter a left parenthesis, which is not an Operator, or end of input, return the right_node
    if (pos == -1 || expr[pos] == '(') return right_node;
    BTNode* head = makeNode(expr[pos--]); // An operator is always expected here.
    head->right = right_node;
    head->left = EXPR();
    return head;
}
BTNode* FACTOR() {
    char input = expr[pos--];
    BTNode* factorized;
    if(input==')'){
        //encounter a right parenthesis, then turn to expr to find the expression inside the parenthesis
        factorized = EXPR();
        pos--;//skip the left parenthesis
    }else{
        //encounter an operand, then create a node to store the operand
        factorized = makeNode(input);
    }
    return factorized;
}
#endif