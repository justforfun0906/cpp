#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,c; cin>>n>>c;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long l=1, r=1e9+10;
    while(r-l>1){
        long long m=(l+r)/2;
        long long sum=0;
        bool fail= false;
        for(int i=0; i<n; ++i){
            long long C = (a[i]+2*m) * (a[i]+2*m);
            if(C>c||sum+C>c){
                fail = true;
                r = m;
                break;
            }
            sum+=C;
        }
        if (fail) continue;
        if(sum <= c)l=m;
        else r=m;
    }
    cout<<l<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)solve();
}