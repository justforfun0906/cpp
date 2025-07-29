#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    set<int> s2;
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.size();
    //iterator
    for(auto it = s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
    int ex = s.count(2);
    bool emp = s.empty();
    auto it = s.find(2);
    if(it!=s.end()){
        cout<<*next(it) + *prev(it);
    }
}