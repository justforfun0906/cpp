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
    if(t->val>=0) return t->val;
    if(t->val== -1){
        return ((1ll*eval(t->lc) + eval(t->rc)) % mod+mod)%mod;
    }
    if(t->val== -2){
        return ((1ll*eval(t->lc) - eval(t->rc)) % mod+mod)%mod;
    }
    if(t->val== -3){
        return ((1ll*eval(t->lc) * eval(t->rc)) % mod+mod)%mod;
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
    build();
    int ans = eval(tree[0]);
    if(t == 1) {
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!check(tree[i], tree[j])){
                    swap(tree[i], tree[j]);
                    int temp = eval(tree[0]);
                    ans = temp > ans ? temp : ans;
                    swap(tree[i], tree[j]);
                }
            }
        }
    }
    else {
        for(int i=0;i<n;i++){
            if(tree[i]->lc!=NULL&&tree[i]->rc!=NULL){
                swap(tree[i]->lc, tree[i]->rc);
                int temp = eval(tree[0]);
                ans = temp > ans ? temp : ans;
                swap(tree[i]->lc, tree[i]->rc);
            }
        }
    }
    printf("%d\n", ans);
}