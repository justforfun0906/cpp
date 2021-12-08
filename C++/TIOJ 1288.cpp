//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
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
int dp[1005][1005];
void solve(){
	int a;
	cin >> a;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=i;j++){
			cin >> dp[i][j];
		}
	}
	for(int i=a-1;i>=1;--i){
		for(int j=1;j<=i;j++){
			dp[i][j]+=max(dp[i+1][j+1],dp[i+1][j]);
		}
	}
	cout<<dp[1][1]; 
}
int main(){
	faster;
	solve();
}

