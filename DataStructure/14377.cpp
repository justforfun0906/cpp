#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
vector<vector<int>> G(N);
int state[N];// 0: not done, 1: in stack, 2: done
int a[N];
int dp[N];
int f(int v){
    if(state[v] == 1){
        return -1;// cycle
    }else if(state[v] == 0){
        dp[v] = a[v];
        state[v] = 1;
        for(auto u:G[v]){
            int res = f(u);
            if(res == -1){
                return -1;
            }
            dp[v] += res;
        }
        state[v] = 2;
    }
    return dp[v];
}
signed main(){
    int n,m;
    cin>>n>>m;  
    for(int i=0;i<m;i++){
        char ins;
        int u,v;
        cin>>ins>>u;
        for(int j='A'; j<ins;j++){
            cin>>v;
            G[u].push_back(v);
        }
        cin>>a[u];
    }
    for(int i=1;i<=n;i++){
        int ans = f(i);
        if(ans == -1){
            cout<<"#REF!\n";
        }else{
            cout<<ans<<'\n';
        }
    }
}