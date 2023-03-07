//code for fun
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define yosoro ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
ll dp[100050][3];
int main(){
	yosoro;
	int n;
	cin>>n;
	int a[n][3];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<3;i++){
		dp[0][i]=a[0][i];
	}
	for(int i=1;i<n;i++){
		dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=a[i][2]+max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<'\n';
}
