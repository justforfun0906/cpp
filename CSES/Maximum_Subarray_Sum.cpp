#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long last=a[0];
    long long best=-1e18;
    for(int i=1;i<n;i++){
        if(a[i]>last+a[i])last=a[i];
        else last+=a[i];
        if(last>best) best=last;
    }
    if(last>best) best=last;
    cout<<best;
}
