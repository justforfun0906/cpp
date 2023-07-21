#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    int now=1,M=1;
    for(int i=0;i<n-1;i++){
        if(a[i]+k<a[i+1])now=1;
        else now++;
        if(now>M)M=now;
    }
    if(now>M)M=now;
    cout<<n-M<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}