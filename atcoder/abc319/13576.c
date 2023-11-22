#include<stdio.h>
int main(){
    long long g,b,s;
    scanf("%lld %lld %lld",&g, &b, &s);
    long long ans = g*b;
    double ans2 = (double)g/s;
    printf("%lld\n", ans);
    printf("%.2lf\n", ans2);
}