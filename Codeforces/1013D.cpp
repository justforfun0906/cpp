#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned main(){
    int n,T,MIN=1e9+5,total=0,ans=0;cin>>n>>T;
    set<int> booths;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        a[i]=temp;
        total+=temp;
        booths.insert(temp);
        MIN=min(temp,MIN);
    }
    ans+=(T/total)*n;
    //cout<<"now ans="<<ans<<'\n';
    T=T%total;
    while(T>=MIN){
        auto it=booths.upper_bound(T);
        //cout<<"it= "<<*it<<'\n';
        if(T>=total){
            ans+=(T/total)*n;
            T=T%total;
        }
        else if(it!=booths.end()){
            total-=*it;
            booths.erase(it);
            n--;
        }
        else{
            for(int i=0;i<n;i++){
                if(T>=a[i]&&booths.count(a[i])){
                    T-=a[i];
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}