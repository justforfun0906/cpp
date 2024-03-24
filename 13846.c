#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *left, *right;
}node;
int N;
void build_tree(int value, node *root);
void print_post_order(int* post, node *root);
node* new_node(int value);
int idx;
int main(){
    scanf("%d", &N);
    int arr[100010];
    int post[100010];
    for(int i=0;i<N;i++){
        scanf(" %d", &arr[i]);
    }
    node* root = new_node(arr[0]);
    for(int i=1;i<N;i++){
        build_tree(arr[i], root);
    }
    idx = 0;
    print_post_order(post,root);
    for(int i=0;i<N-1;i++){
        printf("%d ", post[i]);
    }
    printf("%d\n",post[N-1]);
}
node* new_node(int value){
    node *new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = new->right = NULL;
    return new;
}
void build_tree(int value, node *root){
    if(value <= root->data){
        if(root->left == NULL){
            root->left = new_node(value);
        }
        else{
            build_tree(value, root->left);
        }
    } else{
        if(root->right == NULL){
            root->right = new_node(value);
        }
        else{
            build_tree(value, root->right);
        }
    }
    return;
}
void print_post_order(int* post, node *root){
    if(root == NULL) return;
    print_post_order(post, root->left);
    print_post_order(post, root->right);
    post[idx++] = root->data;
    return;
}