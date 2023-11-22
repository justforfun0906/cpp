#include<stdio.h>
#include<string.h>
int main(){
    int pos[60][100005]={-1};
    char s[100005];
    scanf("%s", s);
    int size = strlen(s);
    for(int i=0;i<size-1;i++){
        char now = s[i];
        if(now - 'a'>=0&&now - 'a'<26){//lower
            for(int j=0;j<100005;j++){
                if(pos[26+(now-'a')][j]==-1){
                    pos[26+(now-'a')][j]=i;
                    break;
                }
            }
        }else{
            for(int j=0;j<100005;j++){
                if(pos[now-'A'][j]==-1){
                    pos[now-'A'][j]=i;
                    break;
                }
            }
        }
    }
    for(int i=0;i<60;i++){
        if(i<=25){
            if(pos[i][0]!=-1){
                printf("%c: ", 'A'+i);
                for(int j=0;j<100005;j++){
                    if(pos[i][j]!=-1){
                        printf("%d ",pos[i][j]);
                    }else{
                        break;
                    }
                }
                printf("\n");
            }
        }else{
            if(pos[i][0]!=-1){
                printf("%c: ", 'a'+i);
                for(int j=0;j<100005;j++){
                    if(pos[i][j]!=-1){
                        printf("%d ",pos[i][j]);
                    }else{
                        break;
                    }
                }
                printf("\n");
            }
        }
    }
}