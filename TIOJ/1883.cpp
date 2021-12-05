//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int dp[105][1005];
int main(){
	faster;
	int c;
	cin>>c;
	while(c--){
		memset(dp,0,sizeof(dp));
		int w,b,n,m;
		cin>>w>>b>>n;
		int d[n+5],v[n+5];
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i];
		}
		cin>>m;
		for(int i=1;i<=n;i++){
			d[i]+=m;
		}
		for(int i=1;i<=n;i++){
			for(int j=d[i];j<=w;j++){
				dp[i][j]=max(dp[i-1][j],dp[i][j-d[i]]+v[i]);
			}
		}
		if(dp[n][w]>=b)cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';	
	}
}

