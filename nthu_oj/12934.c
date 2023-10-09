#include<stdio.h>
#include<string.h>
int main(){
    char a[10000];
    scanf("%s", a);
    int len = strlen(a);
    char b[10000];
    int flag = 1;
    for(int i=0; i<len; i++){
        if(a[len-1-i] == '1')b[i]= '1';
        else if(a[len-1-i]=='6')b[i]='9';
        else if(a[len-1-i]=='9')b[i]='6';
        else if(a[len-1-i]=='8')b[i]='8';
        else if(a[len-1-i]=='0')b[i]='0';
        else flag = 0;
    }
    int first = 0;
    if(flag==0) printf("No\n");
    else{
        for(int i=0;i<len;i++){
            if(b[i]!='0'){
                printf("%c", b[i]);
                first = 1;
            }else if(first == 1){
                printf("%c", b[i]);
            }
        }
        printf("\n");
    }
}