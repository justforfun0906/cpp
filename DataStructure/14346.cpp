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
    int ans_min= 1e9;
    for(int i=0;i<k;i++){
        pq.push(v[i].second);
    }
    ans_min = v[k-1].first + pq.top();
    for(int i=k;i<n;i++){
        pq.pop();
        pq.push(v[i].second);
        ans_min = min(ans_min, v[i].first + pq.top());
        // cout<<"x = "<<v[i].first<<" top = "<<pq.top();
        // cout<<" ans_min = "<<ans_min<<'\n';
    }
    cout<<ans_min<<'\n';
}
