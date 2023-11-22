#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> mp(n+10, 0);
    vector<int> cnt(n+10, 0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp<=n) mp[temp]++;
    }
    int M=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(j*j==i)cnt[i]+=mp[j];
            else if(i%j==0){
                cnt[i]+=mp[j]+mp[i/j];
            }
        }
        M=max(M, cnt[i]);
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