#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    pair<int, int> p;
    p.first = 1;
    p.second = 2;
    vector<pair<int, int> > v;
    v.push_back(make_pair(1,2));
    sort(v.begin(), v.end());
}