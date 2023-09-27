#include<stdio.h>
#include<string.h>
int max(int a, int b){
    if(a>b)return a;
    else return b;
}
int main(){
    char str[1010];
    scanf("%s", str);
    int siz=strlen(str), ans=0;
    for(int i=0;i<siz;i++){
        int sum=0;
        for(int j=0;i-j>=0&&i+1+j<siz;j++){
            if(str[i-j]==str[i+1+j])sum+=2;
            else break;
        }
        ans=max(ans,sum);
    }
    for(int i=0;i<siz;i++){
        int sum=1;
        for(int j=0;i-j-1>=0&&i+1+j<siz;j++){
            if(str[i-1-j]==str[i+1+j])sum+=2;
            else break;
        }
        ans=max(ans,sum);
    }
    printf("%d\n", ans);
    return 0;
}