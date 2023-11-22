#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> check(n);
    for(int i=0;i<n;i++)cin>>check[i];
    sort(check.begin(),check.end());
    for(int i=0;i<n-1;i++){
        if(check[i+1]-check[i]>1)cout<<check[i]+1;
    }
}