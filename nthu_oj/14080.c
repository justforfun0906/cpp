#include <stdio.h>
#include <stdlib.h>
#define N 100001
int cable[N][2], neighborCount[N], *neighbor[N];
int size[N];
int n,ans,balance_size = 1e9;
int max(int a, int b){
    return a>b?a:b;
}
void dfs(int u, int fa){
    size[u]=1;
    int max_son_size=0;
    for(int i=0;i<neighborCount[u];++i){
        int v = neighbor[u][i];
        if(v!=fa){
            dfs(v,u);
            size[u]+=size[v];
            max_son_size = max(max_son_size,size[v]);
        }
    }
    max_son_size = max(max_son_size,n-size[u]);
    if(max_son_size<balance_size){
        ans = u;
        balance_size = max_son_size;
    }
}
int tree_centroid(){
    dfs(1,-1);
    return ans;
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
    // Test the following code
    /*for (int i=1; i<=n; i++) {
        int neighborCnt = neighborCount[i];
        printf("%d connects to ", i);
        for (int j=0; j<neighborCnt; j++) {
            printf("%d ", neighbor[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",tree_centroid());
    return 0;
}