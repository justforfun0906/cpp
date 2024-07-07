#include<bits/stdc++.h>
#define int long long
using namespace std;
int partition(vector<int> &v, int l, int r){
    int pivot = v[l];
    int i=l+1;
    for(int j=l+1;j<=r;j++){
        if(v[j]>pivot){
            swap(v[j],v[i++]);
        }
    }
    swap(v[l],v[i-1]);
    return i;
}
void QuickSort(vector<int> &v,int l, int r){
    if(l>=r)return;
    int pos = partition(v,l,r);
    QuickSort(v,l,pos-1);
    QuickSort(v,pos+1,r);
}
void Merge(vector<int> &v, int l, int r){
    int mid = (l+r)/2;
    vector<int> temp;
    int ind_l = l, ind_r = mid+1;
    while(ind_l<=mid&&ind_r<=r){
        if(v[ind_l]>v[ind_r]){
            temp.emplace_back(v[ind_l++]);
        }else{
            temp.emplace_back(v[ind_r++]);
        }
    }
    while(ind_l<=mid)temp.emplace_back(v[ind_l++]);
    while(ind_r<=r) temp.emplace_back(v[ind_r++]);
    for(int i=0;i<=r-l;i++){
        v[l+i]=temp[i];
    }
}
void MergeSort(vector<int> &v,int l, int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    MergeSort(v,l,mid);
    MergeSort(v,mid+1, r);
    Merge(v,l,r);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    QuickSort(v,0,n-1);
    for(int i=0;i<n;i++) cout<<v[i]<<' ';
    cout<<'\n';
}