#include<bits/stdc++.h>
using namespace std;
int n,k;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b)const{
        int temp_x = max(a.first, a.second);
        int temp_y = max(b.first, b.second);
        return temp_x>temp_y;
    }
};
int main(){
    cin>>n>>k;
    priority_queue<pair<int,int>, vector<pair<int, int>> , cmp> pq;
    //maintain a k-size pq with key_value = max(x, y)
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(pq.size()<k){
            pq.push({x,y});
        }else{
            if(max(x,y)<max(pq.top().first, pq.top().second)){
                pq.pop();
                pq.push({x,y});
            }
        }
    }
    cout<<"in queue:"<<'\n';
    while(!pq.empty()){
        cout<<pq.top().first<<' '<<pq.top().second<<'\n';
        pq.pop();
    }
}