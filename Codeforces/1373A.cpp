#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
		int a,b,c;//$a,donut b,$c
        cin>>a>>b>>c;
        if(c<=a){
            cout<<-1<<' '<<b<<'\n';
        }
        else if(a*b<=c){
            cout<<1<<' '<<-1<<'\n';
        }
        else if(a*b>c){
            cout<<1<<' '<<b<<'\n';
        }
    }
}
