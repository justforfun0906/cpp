#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int price[n+5];
    price[0]=1e9;
    price[n+1]=-1e9;
    long long profit = 0;
    int hold = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&price[i]);
    }
    for(int i=1;i<=n;i++){
        if(price[i-1]>=price[i]&&price[i+1]>=price[i]&&hold == 0){//local minimum
            profit -= price[i];
            //printf("buy at %d\n", price[i]);
            hold = 1;
        }else if(price[i-1]<=price[i]&&price[i+1]<=price[i]&&hold == 1){
            profit += price[i];
            //printf("sell at %d\n", price[i]);
            hold = 0;
        }
    }
    if(hold) profit += price[n];
    printf("%lld\n", profit);
}