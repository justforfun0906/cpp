#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		if(a==0){
			cout<<0;
		}
		else{
			vector<int>v;
			while(a){
				v.push_back(a%10);
				a/=10;
			}
			long long sum=1;
			for(auto i:v)sum*=i;
			cout<<sum<<'\n';
		}
	}
}
