#include<bits/stdc++.h>
using namespace std;
long long ans;
void merge_sort(vector<int> a, int l, int r){//[]
    if(l==r)return;
    int mid = (l+r)/2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);
    vector<int> sorted(r-l+5);
    int li=l,ri=mid+1; //left iterator, right iterator
    int iter=0;//iterator of sorted array
    for(;li<=mid;li++){
        while(ri<=r&&a[ri]<a[li]){
            sorted[iter]=a[ri];
            ri++;iter++;
            ans+=a[ri]+a[li];
            //cout<<a[ri]<<' '<<a[li]<<'\n';
            ans=ans%(int)(1e7+19);
        }
        sorted[iter]=a[li];
        iter++;
    }
    while(ri<=r){
        sorted[iter]=a[ri];
        ri++;iter++;
    }
    cout<<"l="<<l<<" r="<<r<<'\n'
    for(int i=0;i<=r-l;i++){
        a[l+i]=sorted[i];
        cout<<sorted[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ans=0;
    merge_sort(arr,0,n-1);
    //for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    //cout<<ans;
}
