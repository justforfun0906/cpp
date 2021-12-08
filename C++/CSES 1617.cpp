//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
ll mod=1e9+7;
int main(){
	faster;
	int n;
	cin>>n;
	long long ans=1;
	while(n--){
		ans*=2;
		ans=ans%mod;
	}
	cout<<ans;
}

