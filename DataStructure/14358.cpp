#include<bits/stdc++.h>
using namespace std;
const int MaxLen = 5050;
const int MOD = 1000000007;
const int M = 37;
long long pw[MaxLen];
long long len[MaxLen];
long long HashMap[MaxLen];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        HashMap[i] = 0;
        for(int j=0;j<s.size();j++){
            HashMap[i] = (HashMap[i] + s[j] * pw[j] % MOD) % MOD;
        }
        len[i] = s.size();
    }
    while(q--){
        char instruct;
        int x,y;
        cin>>instruct>>x>>y;
        x--; y--;
        if(instruct == 'E'){
            cout<< (HashMap[x]==HashMap[y]?'Y':'N')<<'\n';
        }else{
            HashMap[x] = (HashMap[x]+HashMap[y]*pw[len[x]]%MOD)%MOD;
            len[x]+=len[y];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    for(int i=1;i<MaxLen;i++){
        pw[i] = (pw[i-1]*M)%MOD;
    }
    solve();
}