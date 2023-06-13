#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int t=a[n/2];
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(t-a[i]);
    }
    cout<<sum;
}