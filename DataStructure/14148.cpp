#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int l, int r){
    int pivot = v[l];
    int i = l+1;
    //make sure don't change the location of pivot first
    for(int j=l+1;j<=r;j++){
        if(v[j]>pivot){
            swap(v[j],v[i]);
            i++;
        }
    }
    //from l to i-1, all elements are greater than pivot
    //swap pivot with i-1
    //making sure that pivot is in the correct position
    swap(v[l],v[i-1]);
    //return the correct position of pivot
    return i-1;
}
//remember to use call by reference
int QuickSelect(vector<int> &v,int l, int r, int target){
    int pos = Partition(v,l,r);
    //if l == r, pos will = l
    if(pos==target){
        return v[pos];
    }
    if(pos>target){
        return QuickSelect(v,l,pos-1, target);
    }else{
        //don't need to change the value of target
        //it represent the real value of location in the vector
        //it is not relative
        return QuickSelect(v,pos+1,r, target);
    }
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<QuickSelect(v,0,n-1,k-1)<<'\n';
    return 0;
}