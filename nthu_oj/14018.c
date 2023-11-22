#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
char ans[1000005];
void print(int p){
    for(int i=0;i<p;i++) putchar(ans[i]);
    printf("\n");
}
int main(){
    char c;
    bool valid=true;
    int size = 0, cnt = 0;
    while(1){
        cnt = 0;
        c = getchar();
        if(c==EOF) break;
        if(c=='\n'){
            if(valid) print(size);
            else printf("Domo cannot crack this computer\n");
            size = 0, valid = true;
            continue;
        }
        if(isdigit(c)==0){
            //printf("case1: %c\n", c);
            valid = false;
            continue;
        }
        while(isdigit(c)){
            cnt = cnt*10 +(c-'0');
            c = getchar();
        }
        if(cnt==0){
            //printf("case2\n");
            valid = false;
            continue;
        }
        if(c=='\''){
            c = getchar();
            if(isdigit(c)==0){
                //printf("case3\n");
                valid = false;
                continue;
            }
        }
        while(cnt--) ans[size++]=c;
        if(isdigit(c)){
            c = getchar();
            if(c!='\''){
                valid = false;
                //printf("case4\n");
            }
            if(c=='\n'){
                printf("Domo cannot crack this computer\n");
                size = 0;
                valid = true;
            }
        }
    }//1 loop = a set of cnt*c
}