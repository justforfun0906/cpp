#include<iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int flag = 1;
        for(int i=1;i<=n-2;i++){
            int cnt = a[i-1];
            if(cnt<0){
                flag = 0;
                break;
            }
            a[i-1]-=cnt;
            a[i]-=cnt*2;
            a[i+1]-=cnt;
        }
        for(int i=0;i<n&&flag!=0;i++){
            if(a[i]!=0){
                flag = 0;
                break;
            }
        }
        flag?cout<<"YES\n":cout<<"NO\n";
    }
}