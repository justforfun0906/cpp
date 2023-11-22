#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,h,x;
    cin>>n>>h>>x;
    vector<int> p(n+5);
    for(int i=0;i<n;i++)cin>>p[i];
    int target = x-h;
    for(int i=0;i<n;i++){
        if(p[i]>=target){
            cout<<i+1;
            break;
        }
    }
}