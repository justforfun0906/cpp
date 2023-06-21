#include<bits/stdc++.h>
using namespace std;
long long ask_parant(long long a){
    if(a%2==1){
        return((a-1)/2);
    }
    else return(a/2);
}
void solve(){
    long long n;cin>>n;
    long long sum=0;
    while(n!=1){
        sum+=n;
        n=ask_parant(n);
    }
    cout<<sum+1<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}