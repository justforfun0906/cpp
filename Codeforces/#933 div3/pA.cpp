#include<iostream>
#include<vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int left[n+5], right[m+5];
        for(int i=0;i<n;i++) cin>>left[i];
        for(int i=0;i<m;i++) cin>>right[i];
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(left[i]+right[j]<=k) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}