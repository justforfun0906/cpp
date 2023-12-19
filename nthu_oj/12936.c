#include<stdio.h>
#include<stdlib.h>
int r_len[50][50], c_len[50][50];
char a[50][50];
int check(int n, int m){
    for(int i=0;i<n;i++){
        int len = r_len[i][0];
        int cnt = 0, idx = 0;//idx indicate the r_len , cnt indicate numbers of consecutive o
        for(int j=0;j<=m;j++){
            if(a[i][j] == 'o'){
                cnt++;
            }else if(cnt>0){
                if(idx >= len){//too many consecutive segments
                    return 0;
                }
                if(cnt != r_len[i][++idx]){
                    return 0;
                }
                cnt = 0;
            }
        }
        if(idx!=len)return 0;
    }
    for(int i=0;i<m;i++){
        int len = c_len[i][0];
        int cnt = 0, idx = 0;
        for(int j=0;j<=n;j++){
            if(a[j][i] == 'o'){
                cnt++;
            }else if(cnt>0){
                if(idx >= len){
                    return 0;
                }
                if(cnt != c_len[i][++idx]){
                    return 0;
                }
                cnt = 0;
            }
        }
        if(idx!=len) return 0;
    }
    return 1;
}
void solve(){
    for(int i=0;i<50;i++) for(int j=0;j<50;j++){
        r_len[i][j] = 0;
        c_len[i][j] = 0;
        a[i][j] = 0;
    }
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &r_len[i][0]);
        for(int j=1;j<=r_len[i][0];j++){
            scanf("%d", &r_len[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d", &c_len[i][0]);
        for(int j=1;j<=c_len[i][0];j++){
            scanf("%d", &c_len[i][j]);
        }
    }
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    for(int i=0;i<m;i++) a[n][i] = '\0';
    printf(check(n,m)? "Yes\n" : "No\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}