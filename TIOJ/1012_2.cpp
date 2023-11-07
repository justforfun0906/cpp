#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
    int n,m;
    cin>>n>>m;
    int now=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(now<x)a.push_back(++now);
        auto iter = find(a.begin(),a.end(),x);
        int dis= a.end()-iter;
        if(dis>m+1){
            cout<<"no"<<'\n';
            return 0;
        }else{
            a.erase(iter);
        }
    }
    cout<<"yes"<<'\n';
}
