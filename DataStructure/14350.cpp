#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void merge(vector<pair<int, int>> &v, int l, int r){
    int mid = (l+r)/2;
    vector<pair<int, int> > tmp(r-l+1);
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(v[i].first<=v[j].first){
            tmp[k++] = v[i++];
        }else{
            tmp[k++] = v[j++];
            cnt += mid-i+1;
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
    int mid = (l+r)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    merge(v,l,r);
}
int main(){
    int n;
    cin>>n;
    vector< pair<int, int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        if(v[i].first>v[i].second) swap(v[i].first,v[i].second);
        //make sure that v[i].first<=v[i].second
    }
    merge_sort(v,0,n-1);
}