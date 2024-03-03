#include<stdio.h>
void solve(){
    int n,k; scanf("%d%d", &n, &k);
    int next[n+5];
    for(int i=1;i<=n;i++){
        next[i] = i+1;
    }
    next[n] = -1;
    for(int i=0;i<k;i++){
        int num; scanf("%d", &num);
        if(next[num] == -1){
            printf("Penguin07 QQ\n");
        }else{
            printf("%d\n", next[num]);
            int temp_ind = next[num];
            next[num] = next[next[num]];
            next[temp_ind] = -1;
        }        
    }    
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}