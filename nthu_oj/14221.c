#include <stdlib.h>
#include <stdio.h>
int N;
typedef struct _node {
    char val;
    struct _node* next;
} node;
//list[i]'s head node
node *head[100005] = {};
//list[i]'s tail node
node *tail[100005] = {}; 
//reverse(list[i])'s head node
node *rev_head[100005] = {};
//reverse(list[i])'s tail node
node *rev_tail[100005] = {};
void swap(int a, int b) {
    //swap list[a] and list[b]
    node *tmp = (node*)malloc(sizeof(node));
    //swap(head_node)
    tmp = head[a];
    head[a] = head[b];
    head[b] = tmp;
    //swap(tail_node)
    tmp  = tail[a];
    tail[a] = tail[b];
    tail[b] = tmp;
    //swap(rev_head)
    tmp = rev_head[a];
    rev_head[a] = rev_head[b];
    rev_head[b] = tmp;
    //swap(rev_tail)
    tmp = rev_tail[a];
    rev_tail[a] = rev_tail[b];
    rev_tail[b] = tmp;
    return;
}
void append(int a, int b) {
    //append list[a] to list[b]'s behind
    if(head[a] == NULL) return;
    if(head[b] == NULL) {
        head[b] = head[a];
        tail[b] = tail[a];
        head[a] = NULL;
        tail[a] = NULL;

        rev_head[b] = rev_head[a];
        rev_tail[b] = rev_tail[a];
        rev_head[a] = NULL;
        rev_tail[a] = NULL;
        return;
    }else{
        node *tmp = (node*) malloc(sizeof(node));
        tmp = head[a];
        tail[b]->next = tmp;
        tail[b] = tail[a];
        head[a] = NULL;
        tail[a] = NULL;

        tmp = rev_head[b];
        rev_tail[a]->next = tmp;
        rev_head[b] = rev_head[a];
        rev_tail[a] = NULL;
        rev_head[a] = NULL;
        return;
    }
}
void reverse(int a) {
    //reverse list[a]
    if(head[a] == NULL) return;
    /*
    use rev_head and rev_tail to reverse list[a] in o(1)
    hint: swap something
    */
    node *tmp = head[a];
    tmp = head[a];
    head[a] = rev_head[a];
    rev_head[a] = tmp;
    tmp = tail[a];
    tail[a] = rev_tail[a];
    rev_tail[a] = tmp;
}
void solve(){
    int op, a, b;
    scanf("%d", &op);
    if(op == 1){
        scanf("%d %d", &a, &b);
        append(b,a);
        swap(a,b);
    }else if(op == 2){
        scanf("%d %d", &a, &b);
        append(a, b);
    }else if(op == 3){
        scanf("%d %d", &a, &b);
        swap(a,b);
    }else{
        scanf("%d", &a);
        reverse(a);
    }
}
void test(){
    for(int i=1;i<=N;i++){
        node *tmp = head[i];
        while(tmp != NULL){
            printf("%c", tmp->val);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
int main(){
    scanf("%d", &N);
    //init list
    char s[500005];
    for(int i=1;i<=N;i++){
        int length;
        scanf("%d", &length);
        
        if(length)scanf(" %s", s);
        //init head[i] and tail[i] rev_head[i] and rev_tail[i]
        if(length==0){//empty row
            head[i]=NULL;
            tail[i]=NULL;
            rev_head[i]=NULL;
            rev_tail[i]=NULL;
        }else{//first node
            head[i] = (node *)malloc(sizeof(node));
            head[i]->next = NULL;
            head[i]->val = s[0];
            tail[i] = head[i];
            rev_head[i] = (node *)malloc(sizeof(node));
            rev_head[i]->next = NULL;
            rev_head[i]->val = s[length-1];
            rev_tail[i] = rev_head[i];
        }
        //building normal head and tail
        for(int j=1;j<length;j++){
            node *new_node = (node *)malloc(sizeof(node));
            new_node->val = s[j];
            new_node->next = NULL;
            tail[i]->next = new_node;
            tail[i] = new_node;
        }
        for(int j=length-2;j>=0;j--){
            node *new_node = (node *)malloc(sizeof(node));
            new_node->val = s[j];
            new_node->next = NULL;
            rev_tail[i]->next = new_node;
            rev_tail[i] = new_node;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    test();
}