#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> a, int target){
    int bound=a[0]+2*target;
    int cnt=1;
    for(auto x:a){
        if(x>bound){
            bound=x+2*target;
            cnt++;
            if(cnt>3) return false;
        }
    }
    return true;
}
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    int MAX=0,MIN=1e9+5;
    for(int i=0;i<n;i++){
        cin>>a[i];
        MAX=max(MAX,a[i]);
        MIN=min(MIN,a[i]);
    }
    sort(a.begin(),a.end());
    int l=0,r=MAX-MIN;
    while(l!=r){
        int mid=(l+r)/2;
        if(check(a,mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
}