//code for fun
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
bool map[1005][1005];
ll dp[1005][1005];
ll mod=1e9+7;
int main(){
	faster;
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			char temp;
			cin>>temp;
			if(temp=='.')map[i][j]=1;
		}
	}
	if(map[1][1]==1)dp[1][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(map[i][j-1]==1)dp[i][j]+=dp[i][j-1];
			if(map[i-1][j]==1)dp[i][j]+=dp[i-1][j];
			dp[i][j]=dp[i][j]%mod;
		}
	}
	cout<<dp[m][n];
}


