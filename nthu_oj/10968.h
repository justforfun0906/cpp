#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);
void printInfix(Node *root){
    if(root->left!=NULL){
        printInfix(root->left);
    }
    printf("%c",root->data);
    if(root->right!=NULL){
        if(root->right->data == '&' || root->right->data == '|'){
            printf("(");
            printInfix(root->right);
            printf(")");
        }else{
            printInfix(root->right);
        }
    }
}
void freeTree(Node *root);
#endif