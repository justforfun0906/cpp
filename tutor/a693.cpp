#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n,m,k;
    cin>>m>>n>>k;
    int cnt = m;
    while(m){
        cnt+=m/n;
        m/=n;
        if(cnt>=k)break;
    }
    if(cnt>=k){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}