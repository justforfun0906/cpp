#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    vector<int>find;
    find.push_back(a[0]);
    for(int i=1;i<n;i++){
        int x=a[i];
        for(int j=0;j<find.size();j++){
            find.push_back(x+find[j]);
        }
    }
    sort(find.begin(),find.end());
    cout<<sum-*upper_bound(find.begin(),find.end(),sum/2);
}