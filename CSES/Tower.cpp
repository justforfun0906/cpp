#include<iostream>
#include<set>
using namespace std;
int main(){
    int n; cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        //find the maximum top that is smaller than x
        auto loc = s.upper_bound(x);
        if(loc!=s.end()){
            s.erase(loc);
        }
        s.insert(x);
    }
    cout<<s.size()<<'\n';
}