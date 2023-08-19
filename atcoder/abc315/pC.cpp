#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long,long long> b){
    return a.second > b.second;
}
int main(){
    int n; cin>>n;
    vector<pair<long long, long long> > a(n+5);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;//<flav, satifaction>
    }
    sort(a.begin(), a.end(),cmp);
    int fir=a[0].second;
    int fir_flav=a[0].first;
    if(fir_flav!=a[1].first){
        cout<<fir+(a[1].second/2);
    }
    else{
        long long temp1=fir+(a[1].second/2);
        long long temp2=0;
        for(int i=1;i<n;i++){
            if(a[i].first!=fir_flav){
                temp2 = a[i].second+fir;
                break;
            }
        }
        cout<<max(temp1, temp2);
    }
}