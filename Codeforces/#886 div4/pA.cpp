#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int M=max(a+b,max(b+c,a+c));
        if(M>=10)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}