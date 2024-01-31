#include<stdio.h>
long long len[55];
char find(int i, int k){
    if(i==1) return 'O';
    else if(i == len[k-1]+1) return 'u';
    else if(i == len[k]) return 'Q';
    else{
        if(i<=len[k-1]) return find(i-1,k-1);
        if(i>len[k-1]+2) return find(i-len[k-1]-2,k-1);
    }
}
int main(){
    int k,l,r;
    len[1] = 3;
    for(int i=2;i<=50;i++){
        len[i] = len[i-1]*2+3;
    }
    while(scanf("%d%d%d",&k,&l,&r)!=EOF){
        for(int i=l;i<=r;i++){
            char ans = find(i,k);
            printf("%c",ans);
        }
    }
    printf("\n");
}