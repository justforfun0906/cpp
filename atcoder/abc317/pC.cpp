#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> dp(10000,0);
    vector<vector<pair<int, int> > > g(15); //pair= <connected node, distance>
    //vector<pair<int, int> > w;
    int n,m; cin>>n>>m;
    queue<int> wait;
    for(int i=0;i<m;i++){
        int a,b,d; cin>>a>>b>>d;
        //w.push_back(make_pair(a,b));
        g[a].push_back(make_pair(b,d));
        g[b].push_back(make_pair(a,d));
        int temp= (1<<a) + (1<<b);
        wait.push(temp);
        dp[temp]=d;
    }
    while(!wait.empty()){
        int now = wait.front();
        if(now > 10000)return 0;
        for(int i=1;i<=n;i++){
            if(now&(1<<i)){
                for(auto x:g[i]){
                    int node = x.first;
                    int dis = x.second;
                    if(dp[now+(1<<node)]<dp[now]+dis){
                        dp[now+(1<<node)] = dp[now]+dis;
                        wait.push(now+(1<<node));
                    }
                }
            }
        }
        wait.pop();
    }
    cout<<dp[(1<<(n+1))-2];
}
