#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M; cin>>N>>M;
    set<int> A;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        A.insert(x);
    }
    for(int i=0;i<M;i++){
        int x; cin>>x;
        auto it = A.lower_bound(x);
        if(*it==x){
            cout<<*it<<'\n';
        } else {
            set<int>::iterator prev;
            if(it!=A.begin()){
                prev = it;
                prev--;
            } else {
                cout<<*it<<'\n';
                continue;
            }
            int front_dis = abs(*prev-x);
            int back_dis = abs(*it-x);//it is the first element that is greater or equal to x
            if(front_dis<=back_dis){
                cout<<*prev<<'\n';
            } else {
                cout<<*it<<'\n';
            }
        }
    }
}