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
int arr[100005];
long long dp[100005];
int main(){
	faster;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=2;i<=n;i++){
		long long d[k+1];
		for(int j=1;j<=k;j++){
			if(i-j<1)d[j]=1e9;
			else{
				d[j]=arr[i]-arr[i-j];
				if(d[j]<0)d[j]=-d[j];
				d[j]+=dp[i-j];
			}
		}
		long long min=d[1];
		for(int j=1;j<=k;j++){
			if(d[j]<min)
				min=d[j];
		}
		dp[i]=min;
	}
	cout<<dp[n];
}


