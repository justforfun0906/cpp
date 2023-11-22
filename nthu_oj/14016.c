#include<stdio.h>
int m[2000][2000];
int main(){
    int t,N;
    scanf("%d", &t);
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &m[i][j]);
        }
    }
    while(t--){
        int x,y;
        scanf("%d %d", &x, &y);
        int ans = 0;
        for(int i=0;i<N;i++) ans += m[x][i]+m[i][y];
        for(int i=x, j=y; i<N, j<N; i++, j++) ans +=m[i][j];
        for(int i=x, j=y; i<N, j>=0; i++, j--) ans +=m[i][j];
        for(int i=x, j=y; i>=0, j<N; i--, j++) ans +=m[i][j];
        for(int i=x, j=y; i>=0, j>=0; i--, j--) ans +=m[i][j];
        ans-= 5*m[x][y];
        printf("%d\n", ans);
    }
}