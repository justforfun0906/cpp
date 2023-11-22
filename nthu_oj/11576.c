#include<stdio.h>
int main(){
    int time;
    scanf("%d", &time);
    int hour = time / 100;
    int minute = time % 100;
    if(hour>=12){
        hour -= 12;
        printf("%02d:%02d p.m.", hour, minute);
    }else{
        printf("%02d:%02d a.m.", hour, minute);
    }
}