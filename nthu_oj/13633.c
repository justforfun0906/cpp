#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char s[100000];
    while(scanf("%[^\n]%*c", s)!=EOF){
        bool middle=0;
        int size = strlen(s);
        bool c = s[size-1]=='{'||s[size-1]=='}'||s[size-1]==';'||s[size-1]=='>';
        for(int i=0;i<size;i++){
            if(s[i]==';'&&i!=size-1){
                if(middle==0)printf("%c",' ');
                else printf("%c",';');
            }else{
                printf("%c", s[i]);
                if(s[i]!='}') middle=1;
            }
        }
        if(c==0||(middle&&s[size-1]=='}'))printf(";\n");
        else printf("\n");
    }
}