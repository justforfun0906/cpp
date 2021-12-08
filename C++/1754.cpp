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
	int n;
	cin>>n;
	while(n--){
		long long a,b;
		cin>>a>>b;
		if(a==0&&b==0)cout<<"YES"<<'\n';
		else if(a==0||b==0)cout<<"NO"<<'\n';
		else if((ll)(a+b)%3==0){
			cout<<"YES"<<'\n';
		}
		else cout<<"NO"<<'\n';
	}
}

