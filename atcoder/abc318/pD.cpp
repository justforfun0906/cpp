#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, ans=0; cin>>n;
    vector<vector<long long> > find(n+5);
    for(long long i=0;i<n;i++){
        long long temp; cin>>temp;
        find[temp].push_back(i);
    }
    for(long long i=1;i<=n;i++){
        if(find[i].size()>1){
            long long end = find[i].size();
            long long acc=0;
            for(long long j=1;j<find[i].size();j++){
                ans+=((long long)find[i].size()-j)*(find[i][j]-find[i][j-1]-1)*(j);
            }   
        }
    }
    cout<<ans;
}