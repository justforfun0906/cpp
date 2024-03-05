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
 
/*
list[a] = 1 -> 2 -> 3 -> 4
rev_list[a] = 4 -> 3 -> 2 -> 1
head[a]->val = 1, tail[a]->val = 4
rev_head[a]->val = 4, rev_tail[a]->val = 1
you can use rev_head and rev_tail to get o(1) reverse
*/
 
void swap(int a, int b) {
    //swap list[a] and list[b]
    node *tmp = (node *)malloc(sizeof(node));
 
    /* swap(head_node)
    tmp = head[a];
    head[a] = head[b];
    head[b] = tmp;
    */
 
    /* swap(tail_node)
 
    */

    /*swap(rev_head)
 
    */

    /*swap(rev_tail)
 
    */
}
void append(int a, int b) {
    //append list[a] to list[b]'s behind
    if(head[a] == null) return;
    if(head[b] == null) {
        swap(a, b);
        return;
    }
    /*
    tail[b]->next = head[a];
    tail[b] = ...
    ...
    */
}
void reverse(int a) {
    //reverse list[a]
    if(head[a] == null) return;
    /*
    use rev_head and rev_tail to reverse list[a] in o(1)
    hint: swap something
    */
}
int main(){
    scanf("%d", &N);
    //init list
    for(int i=1;i<=N;i++){
        int length;
        scanf("%d", &length);
        char s[100005];
        scanf("%s", s);
        //init head[i] and tail[i] rev_head[i] and rev_tail[i]
        head[i] = (node *)malloc(sizeof(node));
        head[i]->val = -1;
        head[i]->next = NULL;
        //dummy head node
        tail[i] = head[i];
        rev_head[i] = tail[i];
        rev_tail[i] = head[i];
        //building normal head and tail
        for(int j=0;j<length;j++){
            node *new_node = (node *)malloc(sizeof(node));
            new_node->val = s[j];
            new_node->next = NULL;
            tail[i]->next = new_node;
            tail[i] = new_node;
            rev_head[i] = new_node;
        }
        for(int j=length-1;j>=0;j--){
            node *new_node = (node *)malloc(sizeof(node));
            new_node->val = s[j];
            new_node->next = null;
            rev_tail[i]->next = new_node;
            rev_tail[i] = new_node;
        }
    }
}