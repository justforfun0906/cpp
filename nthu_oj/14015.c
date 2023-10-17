#include<stdbool.h>
#include<stdio.h>
int main(){
    int n,r;
    scanf("%d %d", &n, &r);
    int a[r+5][n+5];
    int e[r+5];
    for(int i=0;i<=r+4;i++){
        e[i]=0;
    }
    for(int i=1;i<=n;i++){
        int temp = i%(2*r-2);
        if(temp<r&&temp!=0){
            //printf("i=%d, pos=%d\n", i, temp%r);
            a[temp%r][e[temp%r]]=i;
            e[temp%r]++;
        }else if(temp==r){
            //printf("i=%d, pos=%d\n", i, r);
            a[r][e[r]]=i;
            e[r]++;
        }else if(temp>r){
            //printf("i=%d, pos=%d\n", i, r-(temp%r));
            a[r-(temp%r)][e[r-(temp%r)]]=i;
            e[r-(temp%r)]++;
        }else{
            //printf("i=%d, pos=%d\n", i, 2);
            a[2][e[2]]=i;
            e[2]++;
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=0;j<e[i];j++){
            if(i==1&&j==0) printf("%d", a[i][j]);
            else printf(" %d", a[i][j]);
        }
    }
    printf("\n");
}