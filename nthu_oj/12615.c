#include<stdio.h>
#include<string.h>
char target[10] = "ICPCASIASG";
int g[105][105];
int n;
int find(int x, int y, int idx){
    if(idx==10) return 1;
    if(x<0||y<0||x>=n||y>=n) return 0;
    if(g[x][y]!=target[idx]) return 0;
    return find(x+1, y+2, idx+1)||find(x-1, y+2, idx+1)||find(x+1, y-2, idx+1)||find(x-1, y-2, idx+1)||find(x+2, y+1, idx+1)||find(x-2, y+1, idx+1)||find(x+2, y-1, idx+1)||find(x-2, y-1, idx+1);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &g[i][j]);
        }
    }
    int flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;i<n;j++){
            if(g[i][j]=='I'){
                if(find(i,j,0)) flag = 1;
            }
        }
    }
    flag?printf("YES\n"):printf("NO\n");
}