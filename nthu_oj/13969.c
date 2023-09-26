#include<stdio.h>
int main(){
    long long x;
    scanf("%lld", &x);
    double year1 = (double)x/365;
    float year2 = (float)x/365;
    long long sec = x * 24 * 60 *60;
    printf("%.6lf %.6f %lld\n", year1, year2, sec);
}