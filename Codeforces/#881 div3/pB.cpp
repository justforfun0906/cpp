#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ind=1,cnt=0,first_ind=0;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        if(temp!=0){
            /*if(first_ind==0&&temp<0){
                cnt++;
                first_ind=-1;
                ind=-1;
            }*/
            if(ind==0&&temp>0)ind=1;
            else if(ind==0&&temp<0)ind=-1;
            else if(ind==1&&temp<0){
                ind=-1;
                cnt++;
            }
            else if(ind==-1&&temp>0){
                ind=1;
                //cnt++;
            }
        }
        sum+=abs(temp);
    }
    cout<<sum<<' '<<cnt<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}