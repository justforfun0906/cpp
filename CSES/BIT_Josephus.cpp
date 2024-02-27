#include<iostream>
#include<vector>
using namespace std;
int n;
int lowbit(int x){
    return x&-x;
}
void mod(int k, vector<int> &BIT, int d){
    while(k<=n){
        BIT[k]+=d;
        k+=k&-k;
    }
}
int find_prefix_sum(int k, vector<int> &BIT){
    int sum=0;
    while(k){
        sum+=BIT[k];
        k-=k&-k;
    }
    return sum;
}
int find_kth(int k, vector<int> &BIT){
    int l=1, r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(find_prefix_sum(mid, BIT)>=k){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    int k;
    cin>>n>>k;
    vector<int> BIT(n+5);
    for(int i=1;i<=n;i++){
        mod(i, BIT, 1);
    }
    while(n){
        k = (k%n)+1;
        int target=find_kth(k, BIT);
        cout<<target<<' ';
        mod(target, BIT, -1);
        n--;
    }
}