#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    priority_queue<int> pq;
    vector< pair<int, int> > v(n);
    //maintain a k-size pq with key_value = max(x, y)
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end());

}
