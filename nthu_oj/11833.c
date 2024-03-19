#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *left, *right;
}node;
int N;
int post_order[200005], in_order[200005], pre_order[200005];
int main(){
    scanf("%d", &N);
}