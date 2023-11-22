#include<stdio.h>
int main(){
    int a,b,c,d;
    int time1, time2;
    scanf("%d:%d\n%d:%d", &a, &b, &c, &d);
    time1 = a*60+b;
    time2 = c*60+d;
    if(time1>time2){
        printf("%d\n", 1440-(time1-time2));
    }else{
        printf("%d\n",time2-time1);
    }
}