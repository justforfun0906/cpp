#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char s[100000];
    while(scanf("%[^\n]", s)!=EOF){
        char sub[10000];
        for(int i=0;i<8;i++)sub[i]=s[i];
        if(strcmp(sub,"#include")==0){
            printf("%s\n",s);
        }else{
            int size = strlen(s);
            bool c = s[size-1]=='{'||s[size-1]=='}';
            for(int i=0;i<size;i++){
                if(s[i]==';'&&i!=size-1){
                    printf(' ');
                }else{
                    printf("%c", s[i]);
                }
            }
            if(c==0)printf(";\n");
            else printf("\n");
        }
    }
}