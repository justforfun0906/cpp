#include<stdio.h>
#include<stdlib.h>
char expr[100];
int true_val[5];
int pos=0;
typedef struct _Node{
    char data;
    int val;
    struct _Node *left, *right;
}node;
node* build_tree(){
    node* root = (node*)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->data = expr[pos];
    if(root->data == '&' || root->data == '|'){
        root->left = build_tree(++pos);
        root->right = build_tree(++pos);
    }
    return root;
}
void printInfix(node* root){
    if(root->left != NULL){
        printInfix(root->left);
    }
    printf("%c", root->data);
    if(root->right != NULL){
        if(root->right->data == '&' || root->right->data == '|'){
            printf("(");
            printInfix(root->right);
            printf(")");
        }else{
            printInfix(root->right);
        }
    }
}
int find_value(node** root){
    if((*root)->data == 'A') return true_val[0];
    if((*root)->data == 'B') return true_val[1];
    if((*root)->data == 'C') return true_val[2];
    if((*root)->data == 'D') return true_val[3];
    if((*root)->data == '&') return find_value(&((*root)->right)) & find_value(&((*root)->left));
    if((*root)->data == '|') return find_value(&((*root)->right)) | find_value(&((*root)->left));
}
int main(){
    scanf("%s", expr);
    node* root = build_tree();
    for(int i=0;i<=15;i++){
        true_val[0] = (i/8)%2;
        true_val[1] = (i/4)%2;
        true_val[2] = (i/2)%2;
        true_val[3] = i%2;
        for(int j=0;j<4;j++) printf("%d ", true_val[j]);
        printf("%d\n", find_value(&root));
    }
}