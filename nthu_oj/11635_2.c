#include<stdio.h>
#include<string.h>
int main(){
    char s[1000005];
    scanf("%s", s);
    int size = strlen(s);
    int upp[26]={0}, low[26]={0};
    for(int i=0;i<size;i++){
        char temp = s[i];
        if(temp-'a'>=0&&temp-'a'<=26){
            low[temp - 'a']=1;
        }else{
            upp[temp - 'A']=1;
        }
    }
    for(int i=0;i<26;i++){
        if(upp[i]>0)printf("%c:", 'A'+i);
        for(int j=0;j<size;j++){
            if(s[j]==('A'+i)){
                printf(" %d", j);
            }
        }
        if(upp[i]>0)printf("\n");
    }
    for(int i=0;i<26;i++){
        if(low[i]>0)printf("%c:", 'a'+i);
        for(int j=0;j<size;j++){
            if(s[j]==('a'+i)){
                printf(" %d", j);
            }
        }
        if(low[i]>0)printf("\n");
    }
}