#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	short sum=0;
	short t;
	short max_time=0;
	cin>>t;
	short max=-10;
	vector<pair<short, short>> a(t);
	for(short i=0;i<t;i++){
		cin>>a[i].first>>a[i].second;
		if(a[i].second==-1)sum-=2;
	}
	for(short i=0;i<t;i++){
		if(max<a[i].second){
			max=a[i].second;
			max_time=a[i].first;
		}
	}
	sum+=(max-t);
	if(sum<0)sum=0;
	cout<<sum<<' '<<max_time;
}
