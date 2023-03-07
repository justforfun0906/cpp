#include<bits/stdc++.h>
using namespace std;
int g[505][505];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<1<<'\n';
		for(int i=2;i<=n;i++){//layer
			cout<<1<<' ';
			for(int j=1;j<i-1;j++){
				cout<<0<<" ";
			}
			cout<<1<<'\n';
		}
	}
}

