#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a==0){
        printf("1 ");
    }else{
        long long temp = 1;
        for(int i=1;i<=a;i++){
            temp *= i;
        }
        printf("%lld ", temp);
    }
    printf("is the answer\n");
}