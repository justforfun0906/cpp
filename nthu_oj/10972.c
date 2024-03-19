#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMSYM 6
char symbol[NUMSYM];
char expr[270];
int position;
typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
typedef struct _Node{
    TokenSet data;
    struct _Node *left, *right;
}BTNode;
BTNode* BuildNode(char c);
BTNode* EXPR();
BTNode* FACTOR();
void define_symbol(){
    symbol[0]='A';
    symbol[1]='B';
    symbol[2]='C';
    symbol[3]='D';
    symbol[4]='&';
    symbol[5]='|';
}
BTNode* BuildNode(char c){
    BTNode *New_Node = (BTNode*) malloc(sizeof(BTNode));
    for(int i = 0 ;i < NUMSYM; i++){
        if(c == symbol[i]) New_Node->data = i;
    }
    New_Node->left = NULL;
    New_Node->right = NULL;
    return New_Node;
}
BTNode* EXPR(){
    BTNode* right_node = FACTOR();
    if(position <0 || expr[position] == '('){
        return right_node;
    }
    BTNode* root = BuildNode(expr[position--]);
    root->right = right_node;
    root->left = EXPR();
    return root;
}
BTNode* FACTOR(){
    char input = expr[position--];
    BTNode* factorized;
    if(input == ')'){
        factorized = EXPR();
        position--;//skip the left parenthesis
    }else{
        factorized = BuildNode(input);
    }
    return factorized;
}
void FreeTree(BTNode* root){
    if(root!=NULL){
        FreeTree(root->left);
        FreeTree(root->right);
        free(root);
    }
    return;
}
void printInfix(BTNode* root){
    if(root->left!=NULL){
        printInfix(root->left);
    }
    printf("%c", symbol[root->data]);
    if(root->right!=NULL){
        if(symbol[root->right->data] == '&'|| symbol[root->right->data]=='|'){
            printf("(");
            printInfix(root->right);
            printf(")");
        }else{
            printInfix(root->right);
        }
    }
}
int main(){
    define_symbol();
    scanf("%s", expr);
    position = strlen(expr)-1;
    BTNode* root = EXPR();
    printInfix(root);
    //FreeTree(root);
}