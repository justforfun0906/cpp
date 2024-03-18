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
    
}
int main(){
    scanf("%s", expr);
    position = strlen(expr)-1;
}