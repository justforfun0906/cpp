#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n,d,p,cost=0;
    cin>>n>>d>>p;
    vector<long long> fee(n);
    for(long long i=0;i<n;i++)cin>>fee[i];
    sort(fee.begin(),fee.end(),greater<long long>());
    int start=-1;
    for(int i=0;i<n;i+=d){
        //cout<<"i="<<i<<'\n';
        long long temp=0;
        if(i+d<n) for(int j=i;j<i+d;j++){
            temp+=fee[j];
        }
        else{
            for(int j=i;j<n;j++) temp+=fee[j];
        }
        //cout<<"temp ="<<temp<<" cost="<<cost<<'\n';
        if(temp>p){
            cost+=p;
        }else{
            //cout<<"i="<<i<<'\n';
            start = i;
            break;
        }
    }
    //cout<<"start ="<<start<<'\n';
    if(start!=-1) for(int i=start;i<n;i++){
        cost+=fee[i];
        //cout<<"cost="<<cost<<'\n';
    }
    cout<<cost;
}