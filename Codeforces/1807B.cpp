#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int even=0, odd=0;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if(temp%2==1)odd+=temp;
			else even+=temp; 
		}
		if(even>odd) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}
