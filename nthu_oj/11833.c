#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *left, *right;
}node;
int N;
int in_order[200005], pre_order[200005];
node* create_node(int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void print_post_order(node* root){
    if(root->left != NULL) print_post_order(root->left);
    if(root->right != NULL) print_post_order(root->right);
    printf("%d ", root->data);
    return;
}
node* build_tree(int *inorder, int *preorder, int inorder_start, int inorder_end, int preorder_start){
    for(int i=preorder_start;i<=preorder_start+inorder_end-inorder_start;i++){//interate by the size of the subtree
        for(int j=inorder_start;j<=inorder_end;j++){
            if(preorder[i] == inorder[j]){//find the root
                node* root = create_node(preorder[i]);
                root->left = build_tree(inorder, preorder, inorder_start, j-1, preorder_start+1);
                root->right = build_tree(inorder, preorder, j+1, inorder_end, preorder_start+(j-inorder_start)+1);//j-inorder_start is the size of the left subtree
                return root;
            }
        }
    }
    return NULL;
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &in_order[i]);
    for(int i=0;i<N;i++) scanf("%d", &pre_order[i]);
    node* root = build_tree(in_order, pre_order, 0, N-1,0);
    print_post_order(root);
    printf("\n");
}