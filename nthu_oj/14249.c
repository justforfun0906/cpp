//remember to use long long
#include<stdio.h>
#include<stdlib.h>
#define MOD 998244353
typedef struct _node{
    int data; //+ -1, - -2, * -3
    long long value;
    struct _node *left , *right;
}node;
char expr[1000];
node* node_pointer[1000]={NULL};
int idx = 0;
int N;
long long max(long long a, long long b){
    return a > b ? a : b;
}
long long evaluate(node *root);//return the beauty of the tree
node* BuildTree();
int check_parent(node *now, node *target);
void swap(node *a, node *b);
int main(){
    long long ans = 0;
    scanf("%d", &N);
    scanf("%s", expr);
    node *root = BuildTree();
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(check_parent(node_pointer[i], node_pointer[j]) == 0){
                swap(node_pointer[i], node_pointer[j]);
                long long temp = evaluate(root);
                ans = max(ans, ((temp%MOD)+MOD)%MOD);
                swap(node_pointer[i], node_pointer[j]);
            }
        }
    }
    printf("%lld\n", ans);
}
node* BuildTree(){
    if(idx >= N) return NULL;
    node *root = (node *)malloc(sizeof(node));
    node_pointer[idx] = root;
    if(expr[idx] >= '0' && expr[idx] <= '9'){
        root->data = expr[idx] - '0';
        idx++;
    }
    else{
        if(expr[idx] == '+') root->data = -1;
        else if(expr[idx] == '-') root->data = -2;
        else root->data = -3;
        idx++;
        root->left = BuildTree();
        root->right = BuildTree();
    }
    return root;
}
int check_parent(node *now, node *target){
    if(now == NULL) return 0;//reach the leaf
    if(now == target) return 1;//find the target
    return check_parent(now->left, target) || check_parent(now->right, target);
}
void swap(node *a, node *b){
    node* temp_node = a->left;
    a->left = b->left;
    b->left = temp_node;

    temp_node = a->right;
    a->right = b->right;
    b->right = temp_node;

    int temp_data = a->data;
    a->data = b->data;
    b->data = temp_data;
}
long long evaluate(node *root){//important: ((val%mod)+mod)%mod
    if(root->data >= 0) return root->data;
    long long left = evaluate(root->left);
    long long right = evaluate(root->right);
    if(root->data == -1) root->value = (1ll*left + right) % MOD;
    else if(root->data == -2) root->value = (1ll*left-right)%MOD;
    else root->value = (1ll*(left * right))%MOD;
    return root->value;
}