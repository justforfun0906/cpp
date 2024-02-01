#include<stdio.h>
long long len[55];
char base[3] = {'O','u','Q'};
char find(int i, int k){
    if(k==1){
        return base[i];
    }
    else if(i==0) return 'O';
    else if(i == len[k-1]+1) return 'u';
    else if(i == len[k]-1) return 'Q';
    else{
        if(i<=len[k-1]) return find(i-1,k-1);
        else return find(i-len[k-1]-2,k-1);
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