#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *left, *right;
}node;
int N;
int in_order[200005], pre_order[200005], in_order_index[200005];
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
}
node* build_tree(int *inorder, int *preorder, int inorder_start, int inorder_end, int preorder_start, int preorder_end){
    for(int i=preorder_start;i<=preorder_end;i++){
        int root_value = preorder[i];
        int root_index = in_order_index[root_value];
        node* root = create_node(root_value);
        if(inorder_start == inorder_end) return root;//no subtree
        if(root_index > inorder_start){//has room for left subtree
            root->left = build_tree(inorder, preorder, inorder_start, root_index-1, preorder_start+1, preorder_start+root_index-inorder_start);
            //inorder start doesn't change; inorder end = left side of root index;
            //preorder start = now + 1; preorder end = preorder start(now) + size of left subtree(root_index-inorder start)
        }
        if(root_index < inorder_end){//has room for right subtree
            root->right = build_tree(inorder, preorder, root_index+1, inorder_end, preorder_start+root_index-inorder_start+1, preorder_end);
            //inorder start = right side of root index; inorder end doesn't change
            //preorder start = now + size of left subtree +1; preorder end doesn't change (why?)
        }
        return root;
    }
    return NULL;
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &in_order[i]);
    for(int i=0;i<N;i++) in_order_index[in_order[i]] = i;
    for(int i=0;i<N;i++) scanf("%d", &pre_order[i]);
    node* root = build_tree(in_order, pre_order, 0, N-1,0, N-1);
    print_post_order(root);
    printf("\n");
}