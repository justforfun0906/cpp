#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};
int main(){
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    priority_queue<int> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    set<int,cmp> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }
    while(!pq2.empty()){
        cout << pq2.top() << '\n';
        pq2.pop();
    }
    for(auto i:s){
        cout << i << '\n';
    }
}