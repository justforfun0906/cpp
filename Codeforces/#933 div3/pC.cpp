#include<iostream>
#include<vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(s[i-1]=='m'&&s[i+1]=='p')cnt++;
        }else if(s[i]=='i'){
            if(s[i-1]=='p'&&s[i+1]=='e')cnt++;
        }else if(s[i]=='p'){
            if(s[i-1]=='a'&&s[i+1]=='i'&&s[i-2]=='m'&&s[i+2]=='e')cnt--;
        }
    }
    cout<<cnt<<'\n';
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}