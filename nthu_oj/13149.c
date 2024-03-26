#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _node{
    char data;
    int value;
    struct _node* left, *right;
}node;
int N = 0;
int idx = 0;
node* build_tree(){

}
int eval(node* root){
    
}
char expr[200005];
int main(){
    scanf("%s",expr);
    N = strlen(expr);
    node* root = build_tree();
    int q; scanf("%d",&q);
    while(q--){
        int value[N+5];
        char temp[200005];
        scanf("%s",temp);
        for(int i=0;i<N;i++){
            value[i+1] = temp[i]-'0';
        }
        printf("%d\n",eval(root));
    }
}