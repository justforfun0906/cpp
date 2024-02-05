#include<stdio.h>
int n,ans = 0;
int g[15][15];
void print_graph(){
    printf("solution: %d\n", ans);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==0){
                printf(".");
            }else{
                printf("Q");
            }
        }
        printf("\n");
    }
}
int checkqueen(int x, int y){
    for(int i=0;i<n;i++){
        if(g[x][i]==1||g[i][y]==1){
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(x+i<n&&y+i<n&&g[x+i][y+i]==1){
            return 0;
        }
        if(x-i>=0&&y-i>=0&&g[x-i][y-i]==1){
            return 0;
        }
        if(x+i<n&&y-i>=0&&g[x+i][y-i]==1){
            return 0;
        }
        if(x-i>=0&&y+i<n&&g[x-i][y+i]==1){
            return 0;
        }
    }
    return 1;
}
void dfs(int now_queen){
    if(now_queen==n){
        //print_graph();
        ans++;
        return;
    }
    //for(int i=now_queen;i<n;i++){
        for(int j=0;j<n;j++){
            if(checkqueen(now_queen,j)&&g[now_queen][j]==0){
                g[now_queen][j] = 1;
                dfs(now_queen+1);
                g[now_queen][j] = 0;
                //dfs(now_queen);
            }
        }
    //}
    return;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j] = 0;
        }
    }
    dfs(0);
    printf("%d\n", ans);
}