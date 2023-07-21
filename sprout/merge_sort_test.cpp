//By Koios1143
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int long long
#define pii pair<int,int>
using namespace std;
int n,Case=1,arr[2000100],ans=0,tmp[2000100];
void merge(int L,int R){
	int mid=(L+R)>>1;
	for(int i=L,j=mid+1,k=L ; k<=R ; k++){
		if(i>mid)
			tmp[k]=arr[j++];
		else if(j>R)
			tmp[k]=arr[i++];
		else if(arr[i]<=arr[j])
			tmp[k]=arr[i++];
		else{
			ans+=(mid-i+1);
			tmp[k]=arr[j++];
		}
	}
	for(int i=L ; i<=R ; i++)
		arr[i]=tmp[i];
}
void merge_sort(int L,int R){
	int mid=(L+R)>>1;
	if(L==R)
		return;
	merge_sort(L,mid);
	merge_sort(mid+1,R);
	merge(L,R);
}
signed main(){
	IOS;
	while(cin>>n && n){
		ans=0;
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}
		merge_sort(0,n-1);
		cout<<"Case #"<<Case++<<": "<<ans<<'\n';
	}
	return 0;
}
