#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int INF = 1e9+7;
        long long a = 1, b=1;
        for(int i=2;i<=n;i++){
            long long new_a = a*4 + b; 
            long long new_b = a + 2*b;
            a = new_a%INF;
            b = new_b%INF;
        }
        printf("%lld\n",(a+b)%INF);
    }
}