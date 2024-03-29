#include<stdio.h>
#include<stdlib.h>
int N;
int pos[200010];
int child[200010][2] = {0};
int parent[200010] = {0};
int ans = 1;
void sol(int root, int l, int r){
    if(!ans) return;
    if(child[root][0] && child[root][1]){//has 2 children
    //they gotta be 1 left and 1 right compared to the root
        if((pos[child[root][0]]> pos[root] && pos[child[root][0]]<=r)//child 0 is right and it's in the range
        && (pos[child[root][1]]<pos[root] && pos[child[root][1]]>=l)){//child 1 is left and it's in the range
            sol(child[root][0],pos[root]+1,r);//check right child
            sol(child[root][1],l,pos[root]-1);//check left child
        }
        else if((pos[child[root][1]]> pos[root] && pos[child[root][1]]<=r)//child 1 is right and it's in the range
        && (pos[child[root][0]]<pos[root] && pos[child[root][0]]>=l)){//child 0 is left and it's in the range
            sol(child[root][1],pos[root]+1,r);//check right child
            sol(child[root][0],l,pos[root]-1);//check left child
        }
        else ans = 0;//if the children are not in the right position
    }else if(child[root][0]){//only has 1 child
        if(pos[child[root][0]]<pos[root] && pos[child[root][0]]>=l){//child is left
            sol(child[root][0],l,pos[root]-1);
        }else if(pos[child[root][0]]>pos[root] && pos[child[root][0]]<=r){//child is right
            sol(child[root][0],pos[root]+1,r);
        }else{
            ans = 0;//if the child is not in the right position
        }
    }else if(child[root][1]){//only has 1 child
        if(pos[child[root][1]]<pos[root] && pos[child[root][1]]>=l){//child is left
            sol(child[root][1],l,pos[root]-1);
        }else if(pos[child[root][1]]>pos[root] && pos[child[root][1]]<=r){//child is right
            sol(child[root][1],pos[root]+1,r);
        }else{
            ans = 0;
        }
    }else{
        return;// no child -> leaf
    }
}
void solve(){
    ans = 1;
    for(int i=0;i<=N;i++){
        parent[i] = 0;
        pos[i] = 0;
        child[i][0] = 0;
        child[i][1] = 0;
    }
    for(int i=1;i<=N;i++){
        int a,b;
        scanf("%d%d",&child[i][0],&child[i][1]);
        parent[child[i][0]] = i;
        parent[child[i][1]] = i;
    }
    for(int i=1;i<=N;i++){
        int temp ;
        scanf("%d",&temp);
        pos[temp] = i;
    }
    int root;
    for(int i=1;i<=N;i++){
        if(parent[i]==0){
            root = i;
            break;
            // root is the node that has no parent
        }
    }
    sol(root,1,N);
    if(ans) printf("YES\n");
    else printf("NO\n");
}
int main(){
    while(scanf("%d",&N)!=EOF){
        solve();
    }
}