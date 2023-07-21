#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int M=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a<=10){
            if(b>M){
                M=b;
                ans=i+1;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}