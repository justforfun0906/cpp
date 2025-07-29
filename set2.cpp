#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for(auto it=s.begin(); it!=s.end(); it++){
        cout<<*it<<endl;
    }
}