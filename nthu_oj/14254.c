#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define mod 998244353 // Define a modulo for the beauty calculation.
typedef struct _Node {
    int val; // {0 ~ 9: number, -1: +, -2: -, -3: *}
    int ans; // evaluate result
    struct _Node *lc, *rc, *p; //Left child, Right child, Parent
} Node;
char expr[2200000] = {}; // Input string representing the preorder expression of the tree.
Node *tree[2200000] = {}; // Array to store pointers to nodes for easy access.
int h, t, n;
int idx = 0;
//TODO: use ans to store the result of the expression tree
//TODO: only calculate the ans when it is swapped
// Function to build the expression tree from the input string.
void reset(Node* t){
    if(t==NULL) return;
    t->ans = -1;//ans = -1 means not calculated yet
    reset(t->p);
}
Node *build() {
    if(idx >= n) return NULL;
    Node *r = (Node *)malloc(sizeof(Node));
    tree[idx] = r; 
    r->ans = -1, r->lc = r->rc = r->p = NULL;
    if(expr[idx] >= '0' && expr[idx] <= '9'){
        r->val = expr[idx] - '0';
        idx++;
    }
    else {
        if(expr[idx] == '+') r->val = -1;
        else if(expr[idx] == '-') r->val = -2;
        else r->val = -3;
        idx++;
        r->lc = build();
        r->rc = build();
        r->lc->p = r;
        r->rc->p = r;
    }
    return r;
}

// Function to evaluate the expression tree and calculate its beauty.
int eval(Node *t) {
    if(t->ans!=-1) return t->ans;
    if(t->val== -1){
        return t->ans=((1ll*eval(t->lc) + eval(t->rc)) % mod+mod)%mod;
    }
    if(t->val== -2){
        return t->ans=((1ll*eval(t->lc) - eval(t->rc)) % mod+mod)%mod;
    }
    if(t->val== -3){
        return t->ans=((1ll*eval(t->lc) * eval(t->rc)) % mod+mod)%mod;
    }
    else{
        return t->ans = t->val;
    }
}
// Function to swap the subtrees rooted at nodes a and b.
void swap(Node *a, Node *b) {
    Node* temp = a->lc;
    a->lc = b->lc;
    b->lc = temp;

    temp = a->rc;
    a->rc = b->rc;
    b->rc = temp;

    int temp_val = a->val;
    a->val = b->val;
    b->val = temp_val;

    int temp_ans = a->ans;
    a->ans = b->ans;
    b->ans = temp_ans;

    reset(a->p);
    reset(b->p);
}
void print_preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->ans);
    print_preorder(root->lc);
    print_preorder(root->rc);
}
// Depth-First Search function to check if target node is in the subtree rooted at 'now'.
bool dfs(Node *now, Node *target) {
    if(now == NULL) return false;
    if(now == target) return true;
    return dfs(now->lc, target) || dfs(now->rc, target);
}

// Function to check if two nodes have an ancestor-descendant relationship.
bool check(Node *a, Node *b) {
    return dfs(a, b) || dfs(b, a);
}

int main() {
    scanf("%d %d", &h, &t);
    scanf("%s", expr);
    n = (1 << (h + 1)) - 1; // n = 2 ^ (h + 1) - 1
    tree[0]= build();
    int ans = tree[0]->ans;
    //print_preorder(tree[0]);
    //printf("\n");
    if(t == 1) {
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!check(tree[i], tree[j])){
                    swap(tree[i], tree[j]);
                    //printf("now swapping %d %d\n", i, j);
                    //print_preorder(tree[0]);
                    //printf("\n");
                    int temp = eval(tree[0]);
                    ans = temp > ans ? temp : ans;
                    //printf("swapping back %d %d\n", i, j);
                    swap(tree[i], tree[j]);
                    //print_preorder(tree[0]);
                    //printf("\n");
                }
            }
        }
    }
    else {
        for(int i=0;i<n;i++){
            if(tree[i]->lc!=NULL&&tree[i]->rc!=NULL){
                swap(tree[i]->lc, tree[i]->rc);
                /*printf("now swapping %d\n", i);
                print_preorder(tree[0]);
                printf("\n");*/
                int temp = eval(tree[0]);
                ans = temp > ans ? temp : ans;
                //printf("swapping back %d\n", i);
                swap(tree[i]->lc, tree[i]->rc);
                /*print_preorder(tree[0]);
                printf("\n");*/
            }
        }
    }
    printf("%d\n", ans);
}