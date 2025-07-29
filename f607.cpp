#include<iostream>
using namespace std;
int main(){
    int n, L;
    cin>>n>>L;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(), v.end());
}