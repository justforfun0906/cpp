#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long q,a,b;
    cin>>q>>a>>b;
    if(q==1){
        cout<<a+b<<'\n';
    }
    else if(q==2){
        cout<<a-b<<'\n';
    }
    else if(q==3){
        cout<<a*b<<'\n';
    }
    else{
        cout<<a/b<<'\n';
    }
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}