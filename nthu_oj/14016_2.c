#include<stdio.h>
int m[2000][2000];
long long h[2000], v[2000], dr[4000], dl[4000];
int main(){
    int t,N;
    scanf("%d\n%d", &t, &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &m[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        long long temp = 0;
        for(int j=0;j<N;j++) temp += m[i][j];
        h[i]=temp;
    }
    for(int i=0;i<N;i++){
        long long temp = 0;
        for(int j=0;j<N;j++) temp += m[j][i];
        v[i]=temp;
    }
    //make use of the value of i-j to determine the iter for dl and dr
    for(int i=0;i<N;i++){
        long long temp=0;
        for(int j=N-1-i, k=0;j<N&&k<N; j++, k++){
            temp += m[j][k];
        }
        dr[i]= temp;
    }
    for(int i=1;i<N;i++){
        long long temp = 0;
        for(int j=i, k=0;j<N&&k<N; j++, k++){
            temp += m[k][j];
        }
        dr[N-1+i]=temp;
    }
    //fuck you
    for(int i=0;i<N;i++){
        long long temp = 0;
        for(int j=i, k=0; j>=0&&k<N; j--,k++){
            temp += m[k][j];
        }
        dl[i]=temp;
    }
    for(int i=1;i<N;i++){
        long long temp = 0;
        for(int j=i, k = N-1; j<N&&k>=0; j++, k--){
            temp += m[j][k];
        }
        dl[N-1+i]=temp;
    }
    /*for(int i=0;i<=2*N-2;i++){
        printf("%lld ", dr[i]);
    }
    printf("\n");
    for(int i=0;i<=2*N-2;i++){
        printf("%lld ", dl[i]);
    }*/
    while(t--){
        int x,y;
        scanf("%d %d", &x, &y);
        long long ans =0;
        ans += h[x];
        ans += v[y];
        if(x>=y) ans +=dr[(N-1)-(x-y)];
        else ans += dr[(N-1)+(y-x)];
        ans += dl[x+y];
        printf("%lld\n", ans-3*m[x][y]);
    }
}