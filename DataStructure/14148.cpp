#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int l, int r){
    int pivot = v[l];
    int i = l+1;
    for(int j=l+1;j<=r;j++){
        if(v[j]>pivot){
            swap(v[j],v[i]);
            i++;
        }
    }
    swap(v[l],v[i-1]);
    // for(int temp = l; temp<=r;temp++){
    //     cout<<v[temp]<<' ';
    // }
    // cout<<'\n';
    return i-1;
}
int QuickSelect(vector<int> v,int l, int r, int target){
    int pos = Partition(v,l,r);
    if(l==r){
        return v[l];
    }
    if(pos==target){
        return v[pos];
    }
    int mid = (l+r)/2;
    if(pos>target){
        return QuickSelect(v,l,pos,target);
    }else{
        return QuickSelect(v,pos+1,r,target-pos);
    }
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<QuickSelect(v,0,n-1,k-1);
}