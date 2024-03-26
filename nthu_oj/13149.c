#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char value[200005];
char expr[200005];
typedef struct _node{
    int data;//to store the num only, doesn't need to store the operator
    struct _node* left, *right;
}node;
int N = 0;
int idx = 0;
node* new_node(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node* EXPR(){
    int num = 0;
    while(isdigit(expr[idx])&&idx<N){//parse the number
        num = num*10 + (expr[idx]-'0');
        idx++;
    }
    node* root = new_node(num);
    if(expr[idx]=='?'){//if it's a conditional operator
        idx++;//skip '?'
        root->left = EXPR();
        root->right = EXPR();
        return root;//return the root of the subtree
    }
    idx++;//skip ':'
    return root;
}
int eval(node* root){
    if(root->left==NULL&&root->right==NULL){
        return value[root->data-1]-'0';
    }else{
        if(value[root->data-1]=='1') return eval(root->left);
        else{
            return eval(root->right);
        }
    }
}
void print_preorder(node* root){
    if(root==NULL) return;
    printf("%c",root->data);
    print_preorder(root->left);
    print_preorder(root->right);
    return;
}
char expr[200005];
int main(){
    scanf("%s",expr);
    N = strlen(expr);
    idx = 0;
    int q; scanf("%d",&q);
    node* root = EXPR();
    //print_preorder(root);
    while(q--){
        scanf("%s",value);
        printf("%d\n",eval(root));
    }
}