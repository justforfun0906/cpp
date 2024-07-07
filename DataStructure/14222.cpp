#include<iostream>
#include<set>
#include<vector>
#define int long long
using namespace std;
bool BinarySearch(vector<int> &v, int target){
    int l = 0, r = v.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]==target) return 1;
        else if(v[mid]>target) l = mid+1;
        else r = mid - 1;
    }
    return 0;
}
signed main(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l = 0, r = n-1;
    while(q--){
        int x;
        cin>>x;
        BinarySearch(v,x)?cout<<"Y ":cout<<"N ";
    }
}