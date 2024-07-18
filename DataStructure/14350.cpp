#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt = 0;
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
void merge(vector<pair<int, int>> &v, int l,int mid, int r){
    vector<pair<int, int> > tmp(r-l+1);
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(v[i].second<=v[j].second){
            cnt +=r-j+1;
            tmp[k++] = v[i++];
        }else{
            tmp[k++] = v[j++];
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
void merge_sort(vector<pair<int, int> > &v, int l, int r){
    if(l>=r) return;
    int mid = l+(r-l)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    merge(v,l,mid,r);
}
signed main(){
    int n;
    cin>>n;
    vector< pair<int, int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        if(v[i].first>v[i].second) swap(v[i].first,v[i].second);
        //make sure that v[i].first<=v[i].seconda
    }
    sort(v.begin(),v.end(),compare);
    merge_sort(v,0,n-1);
    cout<<cnt<<'\n';
}