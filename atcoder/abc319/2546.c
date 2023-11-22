#include<stdio.h>
int main(){
    int a[4];
    for(int i=0;i<4;i++) a[i] = 0;
    int b;
    scanf("%d", &b);
    for(int i=0;i<4;i++){
        a[i]+=b%2;
        b/=2;
    }
    for(int i=3;i>=0;i--){
        printf("%d", a[i]);
    }
    printf("\n");
}