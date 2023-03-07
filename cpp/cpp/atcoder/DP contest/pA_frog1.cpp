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
int main(){
	faster;
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	vi dp(n+1,0);
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int d1=arr[i]-arr[i-1];
		if(d1<0)d1=-d1;
		int d2=0;
		if(i==2)d2=d1;
		else d2=arr[i]-arr[i-2];
		if(d2<0)d2=-d2;
		dp[i]=min(dp[i-1]+d1,dp[i-2]+d2);
	}
	cout<<dp[n];
}


