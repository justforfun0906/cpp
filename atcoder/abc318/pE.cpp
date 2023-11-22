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
            for(long long j=0;j<end;j++){
                ans +=j*find[i][j]-acc;
                acc+=find[i][j]+1;
                //cout<<"i="<<i<<" acc="<<acc<<'\n';
            }
            long long temp=0;
            for(int i=1;i<=end-1;i++){
                temp+=i*(end-1-i);
            }
            ans-= temp;
        }
        //cout<<ans<<'\n';
    }
    cout<<ans;
}