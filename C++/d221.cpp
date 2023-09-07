#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<int> > pq;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            pq.push(temp);
        }
        for(int i=0;i<n-1;i++){
            int temp = pq.top();
            pq.pop();
            cost += temp + pq.top();
            temp += pq.top();
            pq.pop();
            pq.push(temp);
        }
        cout<<cost<<'\n';
    }
}