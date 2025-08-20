#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){//a是左邊的數字 b是右邊的
    if(a>b) return true;//不交換位置
    else return false;//交換位置
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0;i<n;i++){
        cout<<v[i].second<<' ';
    }
}