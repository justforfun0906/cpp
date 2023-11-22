#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        int a[n+5][n+5];
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                scanf("%d", &a[i][j]);
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ", a[i][j]);
            printf("\n");
        }*/
        int b[m+5][m+5];
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++) scanf("%d", &b[i][j]);
        }
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<=n-m;j++){
                int temp = 0;
                for(int k=i;k<i+m;k++){
                    for(int l=j;l<j+m;l++) temp += a[k][l]*b[k-i][l-j];
                }
                //printf("%d ", temp);
                if(temp>k)cnt++;
            }
            //printf("\n");
        }
        printf("%d\n", cnt);
    }
}