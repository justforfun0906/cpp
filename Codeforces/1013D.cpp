#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,MIN=1e9+5;
    long long T,total=0,ans=0;
    cin>>n>>T;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        MIN=min(a[i],MIN);
    }
    while(T>=MIN){
        int booth_num=0;
        total=0;
        for(int i=0;i<n;i++){
            if(T>=a[i]){
                T-=a[i];
                ans++;
                total+=a[i];
                booth_num++;
            }
        }
        ans+=(T/total)*booth_num;
        T=T%total;
    }
    cout<<ans;
}