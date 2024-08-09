#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};
struct cmp2{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> all; // highest courage first
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> team;
    for(int i=0;i<n;i++){
        int attack, courage;
        cin>>attack>>courage;
        pair<int, int> now = make_pair(attack, courage);
        all.push(now);
    }
    while(!all.empty() && all.top().second >= m){
        team.push(all.top());
        all.pop();
    }
    while(!team.empty()&&m>0){
        pair<int, int> now = team.top();
        team.pop();
        m -= now.first;
        cnt++;
        while(!all.empty() && all.top().second >= m){
            team.push(all.top());
            all.pop();
        }
    }
    if(m>0){
        cout<<-1<<'\n';
    }else{
        cout<<cnt<<'\n';
    }
}