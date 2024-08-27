#include<bits/stdc++.h>
#define ine long long
using namespace std;
const int  N = 1e5+10;
vector<int> G[N];
int state[N];// 0: unvisited, 1: in stack, 2: done
int dp[N];
int a[N];
int f(int x){
    if(state[x]== 1){
        return -1;// cycle
    }
    if(state[x]== 0){
        state[x] = 1;//in stack
        dp[x] = a[x];
        for(auto u:G[x]){
            int res = f(u);
            if(res == -1){
                return -1;// cycle
            }else{
                dp[x] += res;
            }
        }
        state[x] = 2;//done
    }
    return dp[x];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        char ins;
        int u,v;
        cin>>ins>>u;
        for(int j='A';j<ins;j++){
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