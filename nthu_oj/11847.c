#include<stdio.h>
#include<stdlib.h>
char expr[100];
int true_val[5];
typedef struct _Node{
    char data;
    int val;
    struct _Node *left, *right;
}node;
node* build_tree(int pos){
    node* root = (node*)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->data = expr[pos];
    if(expr[pos] == '&' || expr[pos] == '|'){
        root->left = build_tree(pos+1);
        root->right = build_tree(pos+2);
    }
    return root;
}
int find_value(node** root){
    if((*root)->data == 'A') return true_val[0];
    if((*root)->data == 'B') return true_val[1];
    if((*root)->data == 'C') return true_val[2];
    if((*root)->data == 'D') return true_val[3];
    if((*root)->data == '&') return find_value(&((*root)->left)) & find_value(&((*root)->right));
    if((*root)->data == '|') return find_value(&((*root)->left)) | find_value(&((*root)->right));
}
int main(){
    scanf("%s", expr);
    node* root = build_tree(0);
    for(int i=0;i<=15;i++){
        true_val[0] = i%2;
        true_val[1] = (i/2)%2;
        true_val[2] = (i/4)%2;
        true_val[3] = (i/8)%2;
        for(int j=3;j>=0;j--) printf("%d ", true_val[j]);
        printf("%d\n", find_value(&root));
    }
}