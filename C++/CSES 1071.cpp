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
	int t;
	cin>>t;
	while(t--){
		long long y,x,ans;
		cin>>y>>x;
		if(y>x){
			if(y%2==0){
				ans=y*y-x+1;
			}
			else{
				ans=(y-1)*(y-1)+x;
			}
		}
		else{
			if(x%2==0){
				ans=(x-1)*(x-1)+y;
			}
			else{
				ans=x*x-y+1;
			}
		}
		cout<<ans<<'\n';
	}
}

