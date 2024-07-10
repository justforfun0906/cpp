#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
void merge(vector<int> &v, int l, int r){
    int mid = (l+r)/2;
    vector<int> tmp(r-l+1);
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(v[i]<=v[j]){
            tmp[k++] = v[i++];
        }else{
            tmp[k++] = v[j++];
            ans += mid-i+1;
        }
    }
    while(i<=mid){
        tmp[k++] = v[i++];
    }
    while(j<=r){
        tmp[k++] = v[j++];
    }
    for(int i=l;i<=r;i++){
        v[i] = tmp[i-l];
    }
}
void mergeSort(vector<int> &v, int l, int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,r);
}
signed main(){
    cin>>n;
    ans = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    mergeSort(v,0,n-1);
    cout<<ans<<'\n';
}