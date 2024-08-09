#include<bits/stdc++.h>
#define int long long
using namespace std;
int get_dis(int xa, int ya, int xb, int yb){
    return (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb);
}
//use prim to find mst
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> x(n), y(n);
    vector<bool> visited(n, false);
    vector<int> dis(n, 1e18);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    int mn, sum = 0, now = 0, next = 0;
    visited[now] = 1;//put the first node into mst
    for(int round = 0; round < n-1 ; round++){
        dis[now] = 1e18;
        mn = 1e18;
        for(int i=0;i<n;i++){//update dis with new added node
            if(visited[i])continue;
            dis[i] = min(dis[i], get_dis(x[now], y[now], x[i], y[i]));
        }
        for(int i=0;i<n;i++){//find the nearest node that is not visited
            if(visited[i])continue;
            if(dis[i] < mn){
                mn = dis[i];
                next = i;
            }
        }
        visited[next] = 1;
        sum += dis[next];
        now = next;
    }
    cout<<sum<<'\n';
}