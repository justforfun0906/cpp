#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    int t,min_d=1e9;
    pair<int,int>ans;
    cin>>x>>y>>t;
    while(t--){
        int tx,ty;
        cin>>tx>>ty;
        int dis=((tx-x)*(tx-x))+((ty-y)*(ty-y));
        if(dis<min_d){
            min_d=dis;
            ans.first=tx;
            ans.second=ty;
        }
    }
    cout<<ans.first<<' '<<ans.second;
}