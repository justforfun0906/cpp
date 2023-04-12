#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long fpow(long long a, long long b){
		long long result=1;
		while(b>0){
			if(b&1) result=result*a%MOD;
			a=a*a%MOD;
			b>>=1;
		}
		return result;
	}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<fpow(a,b)<<'\n';
	}
}
