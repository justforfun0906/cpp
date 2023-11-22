#include<stdio.h>

int main(){
    char str[4];
    scanf("%s", str);
    double a = (str[0]-'0') + (str[2]-'0');
    double b = (str[1]-'0') + (str[3]-'0');
    double ans = a/b;
    printf("%.2f\n", ans);
    return 0;    
}