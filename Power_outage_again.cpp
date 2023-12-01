#include <stdio.h>
#include <stdlib.h>
#define N 100001

int cable[N][2], neighborCount[N], *neighbor[N];
int n;
int max_depth[N];
int ans = 1e9;
int ans_loc = 1;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
void dfs(int u, int fa, int depth_to_root){
    max_depth[u]=depth_to_root;
    for(int i=0;i<neighborCount[u];i++){
        int v = neighbor[u][i];
        if(v!=fa){
            dfs(v,u,depth_to_root+1);
            max_depth[u]=max(max_depth[u],max_depth[v]+1);
        }
        if(max_depth[u]<ans){
            ans = max_depth[u];
            ans_loc = u;
        }
    }
}

void readGraph() {
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &cable[i][0], &cable[i][1]);
        neighborCount[cable[i][0]]++;
        neighborCount[cable[i][1]]++;
    }
    for (int i=1; i<=n; i++) {
        neighbor[i] = (int*)malloc(neighborCount[i] * sizeof(int));
    }
    int neighborIndex[N] = {};
    for (int i=0; i<n-1; i++) {
        int u = cable[i][0], v = cable[i][1];
        neighbor[u][neighborIndex[u]++] = v;
        neighbor[v][neighborIndex[v]++] = u;
    }
}

int main() {
    readGraph();
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        printf("%d: %d\n",i, max_depth[i]);
    }
    return 0;
}