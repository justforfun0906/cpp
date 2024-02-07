#include<stdio.h>
int isLeap(int year){
    if(year%400==0){
        return 1;
    }else if(year%100==0){
        return 0;
    }else if(year%4==0){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int year;
        scanf("%d", &year);
        int leap = isLeap(year);
        int day = 0;
        while(1){
            year++;
            day+=isLeap(year)?2:1;
            day%=7;
            if(day==0&&isLeap(year)==leap){
                break;
            }
        }
        printf("%d\n", year);
    }
}