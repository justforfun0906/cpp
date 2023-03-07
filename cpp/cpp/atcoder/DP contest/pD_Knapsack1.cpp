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
long long dp[105][100005];
int weight[105];
long long value[105];
int main(){
	faster;
	int n,bag;
	cin>>n>>bag;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>value[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=bag;j++){
			if(weight[i]>j) dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]);//dp[i-1]一定沒有拿過自己這項物品，所以不怕重複拿 
			}
		}
	}
	cout<<dp[n][bag];
}


