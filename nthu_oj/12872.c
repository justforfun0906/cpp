#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x = (7*n-m)/2;
    int y = n-x;
    printf("%d %d\n",x,y);
}