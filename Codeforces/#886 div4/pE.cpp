#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n,c; cin>>n>>c;
    long long sum=0, sq_sum=0;
    for(long long i=0;i<n;i++){
        long long temp;
        cin>>temp;
        sum+=temp;
        sq_sum+=temp*temp;
    }
    c-=sq_sum;
    long long l=0, r=sqrt(c)+10;
    while(l!=r){
        long long m=(l+r)/2;
        long long num = n*m*m + 2*sum*m;
        if(num==c){
            cout<<m/2<<'\n';
            break;
        }
        else if(num<=c)l=m+1;
        else r=m;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)solve();
}