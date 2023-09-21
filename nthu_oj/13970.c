#include<stdio.h>
int main(){
    char note;
    int origin;
    scanf("%c%d", &note, &origin);
    int convert = 0;
    int now =1;
    while(origin){
        if(origin%10==1){
            convert+=now;
        }
        origin/=10;
        now*=2;
    }
    if(note=='1')printf("%c\n",'a'+convert-1);
    else printf("%c\n",'A'+convert-1);
}