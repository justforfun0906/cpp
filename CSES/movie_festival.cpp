#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    int cur_end=-1;
    for(int i=0;i<n;i++){
        if(arr[i].second>=cur_end){
            cur_end=arr[i].first;
            cnt++;
        }
    }
    cout<<cnt;
}
