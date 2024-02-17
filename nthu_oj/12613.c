#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long A, B;
        scanf("%lld%lld", &A, &B);
        int cnt = 0, temp  = 10;
        while(temp-1<B){
            cnt++;
            temp*=10;
        }
        printf("%lld\n", A*cnt);
    }
}