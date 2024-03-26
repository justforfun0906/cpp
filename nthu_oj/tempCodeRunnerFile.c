#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int value[200005];
char expr[200005];
typedef struct _node{
    char data;
    int value;
    struct _node* left, *right;
}node;
int N = 0;
int idx = 0;
node* new_node(char data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->value = -1;//not evaluated yet
    temp->left = temp->right = NULL;
    return temp;
}
node* EXPR(){
    if(idx>=N-1||expr[idx+1]!='?'){
        node* root = new_node(expr[idx]);
        printf("making a leaf node with data %c and idx +=2\n",expr[idx-2]);
        //return root;
    }
    if(expr[idx+1]=='?'){
        node* root = new_node(expr[idx]);
        idx+=2;
        //printf("making an expr root with data %c\n",expr[idx]);
        root->left=EXPR();
        idx+=2;
        //printf("left node with data %c\n",root->left->data);
        root->right=EXPR();
        //printf("right node with data %c\n",root->right->data);
        return root;
    }
}
int eval(node* root){
    if(root->left!=NULL&&root->right!=NULL){
        if(value[(root->data)-'0']==1){
            return eval(root->left);
        }else{
            return eval(root->right);
        }
    }else{
        return value[root->data-'0'];
    }
}
void print_preorder(node* root){
    if(root==NULL) return;
    printf("%c",root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}
char expr[200005];
int main(){
    scanf("%s",expr);
    N = strlen(expr);
    int q; scanf("%d",&q);
    node* root = EXPR();
    //print_preorder(root);
    while(q--){
        char temp[200005];
        scanf("%s",temp);
        idx = 0;
        for(int i=0;i<N;i++){
            value[i+1] = temp[i]-'0';
        }
        printf("%d\n",eval(root));
    }
}