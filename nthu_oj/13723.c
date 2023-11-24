#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,k;
int cnt[1005]={0};
char transed[1005][500];
int len[1005]={0};
int seven_cnt[1005]={0};
int ans[1005];
int cmp1(int i, int j){//return 1 means swap
    if(seven_cnt[i]<seven_cnt[j]) return 1;
    else if(seven_cnt[i]>seven_cnt[j]) return -1;
    else{
        if(len[i]<len[j]) return 1;
        else if(len[i]>len[j]) return -1;
        else{
            int res = strcmp(transed[i], transed[j]);
            if(res>0) return -1;
            else if (res<0) return 1;
            else return 0;
        }
    }
}
int cmp2(int i,int j){
    if(len[i]<len[j]) return -1;
    else if(len[i]>len[j]) return 1;
    else return strcmp(transed[i],transed[j]);
}
void srt1(){//sort all
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(cmp1(ans[j],ans[j+1])>0){//swap;
                int temp = ans[j+1];
                ans[j+1]=ans[j];
                ans[j] = temp;
            }
        }
    }
}
void srt2(){//sort first k
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-1-i;j++){
            if(cmp2(ans[j],ans[j+1])>0){//swap
                int temp = ans[j+1];
                ans[j+1] = ans[j];
                ans[j] = temp;
            }
        }
    }
}
void transfer(char *input, int num){
    for(int i=0,j=0;input[j]!='\0';i=j+1){//j always ahead of i, if j == '\0', it's the end.
        j=i;
        while(input[j]!='|'&&input[j]!='\0')j++;
        int temp = 0;
        char s_hex[20]={'\0'};
        char s_dec[20]={'\0'};
        strncpy(s_hex,input+i,j-i);
        sscanf(s_hex, "%x", &temp);
        sprintf(s_dec, "%d", temp);
        strcat(transed[num],s_dec);
    }
    len[num]=strlen(transed[num]);
    for(int i=0;i<len[num];i++){
        if(transed[num][i]=='7') seven_cnt[num]++;
    }
}
int main(){
    scanf("%d %d", &n, &k);
    char input[2000];
    for(int i=0;i<n;i++){
        scanf("%s",input);
        transfer(input, i);
        ans[i]=i;
    }
    srt1();
    srt2();
    for(int i=0;i<k;i++){
        printf("%s\n",transed[ans[i]]);
    }
}