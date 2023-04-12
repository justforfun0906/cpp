#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	cin>>n>>x;
	vector<pair<int,int> >arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second=i+1;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		int target=x-arr[i].first;
		pair<int,int> temp = *lower_bound(arr.begin(),arr.end(), make_pair(target,0));
		if(temp.first==target){
			if(arr[i].second!=temp.second){
				cout<<arr[i].second<<" "<<temp.second;
				return 0;
			} 
		}
	}
	cout<<"IMPOSSIBLE";
}
