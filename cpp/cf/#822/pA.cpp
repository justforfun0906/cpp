#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a.begin(),a.end());
		int mIn=1e9;
		for(int i=1;i<n-1;i++){
			if((a[i]-a[i-1])+(a[i+1]-a[i])<mIn) mIn=(a[i]-a[i-1])+(a[i+1]-a[i]);
		}
		cout<<mIn<<'\n';
	}
}
