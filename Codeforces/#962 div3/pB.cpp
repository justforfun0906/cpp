#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k; cin>>n>>k;
    vector< vector<int> > v(n, vector<int>(n));
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<n;j++){
            v[i][j] = s[j]-'0';
        }
    }
    int w = n/k;
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            cout<<v[i*k][j*k];
        }
        cout<<'\n';
    }
}
int main(){
    int q; cin>>q;
    while(q--){
        solve();
    }
}