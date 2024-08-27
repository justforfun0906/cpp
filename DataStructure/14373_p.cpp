#include<bits/stdc++.h>
#define int long long
using namespace std;
int get_dis(int xa, int ya, int xb, int yb){
    return (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb);
}
signed main(){
    int n;
    cin>>n;
    int cord_x[n], cord_y[n];
    for(int i=0; i<n; i++){
        cin>>cord_x[i]>>cord_y[i];
    }
    vector<int> dis(n, 1e18);
    vector<bool> visited(n, false);
    int mn, sum = 0, now = 0, next = 0;
    visited[now] = 1;//put an arbitrary point as the starting point
    //Prim's algorithm
    for(int round = 0;round<n-1;round++){
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            else{
                dis[i] = min(dis[i], get_dis(cord_x[now], cord_y[now], cord_x[i], cord_y[i]));
            }
        }
        mn = 1e18;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            else{
                if(dis[i] < mn){
                    mn = dis[i];
                    next = i;
                }
            }
        }
        visited[next] = 1;
        sum += dis[next];
        now = next;
    }
    cout<<sum<<'\n';
}