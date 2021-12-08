//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	faster;
	long long n;
	cin>>n;
	long long ans=0;
	long long mod=5;
	while(mod<=n){
		ans+=n/mod;
		mod=mod*5;
	}
	cout<<ans;
}

