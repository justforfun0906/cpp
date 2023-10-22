#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
int main(){
    char s[1005];//original input
    while(scanf("%s", s)!=EOF){
        char a[1005], ans[1000005]={0};//a = s without ''
        int len = strlen(s);
        int now=0;
        int cnt=0;//counter of '
        bool invalid = 0;
        for(int i=0;i<len;i++){
            if(s[i]!='\''){
                a[now]=s[i];
                now++;
            }else{
                cnt++;
                if(s[i+2]=='\''&&isdigit(s[i+1])==0&&cnt%2==1) invalid = true;//char in the quotes is not an digit
            }
        }
        len = len-cnt;//a's length
        if(len%2==1) invalid = true;
        int times=0;
        now = 0;
        for(int i=0;i<len&&invalid==0;i++){
            if(i%2==0){
                times=a[i]-'0';
                if(times==0||isdigit(a[i])==0)invalid = true;
            }else{
                for(int j=0;j<times;j++){
                    ans[now]=a[i];
                    now++;
                }
            }
        }
        if(invalid) printf("Domo cannot crack this computer\n");
        else printf("%s\n", ans);
    }
}