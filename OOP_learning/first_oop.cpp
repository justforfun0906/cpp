#include<bits/stdc++.h>
using namespace std;
auto cmp = [](int a, int b){
    return a>b;
};
int main(){
    set<int, function<bool(int, int)>> s(cmp);
    s.insert(1);
    s.insert(2);
}