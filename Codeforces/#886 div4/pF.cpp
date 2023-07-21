#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n+10,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        int loc=temp;
        while(loc<=n){
            cnt[loc]++;
            loc+=temp;
        }
    }
    int M=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>M)M=cnt[i];
    }
    cout<<M<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}