#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMSYM 6
char symbol[NUMSYM];
char expr[270];
int position;
typedef struct _Node{
    TokenSet data;
    struct _Node *left, *right;
}BTNode;
typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
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
    if(position < 0 || expr[position]=='(') return right_node;
    BTNode* head = BuildNode(expr[position--]);
    head->right = right_node;
    head->left = EXPR();
    return head;
}
BTNode* FACTOR(){
    char input = expr[position--];
    BTNode* fac;
    if(input == ')'){
        fac = EXPR();
        position--;//skip (
    }else{
        fac = BuildNode(input);
    }
    return fac;
}
int main(){
    scanf("%s", expr);
    position = strlen(expr)-1;
}