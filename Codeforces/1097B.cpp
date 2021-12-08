//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
bool dp[16][360]{0};
int main(){
	faster;
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int d=0;d<360;d++){
			if(dp[i-1][d]){
				int clock_wise=d+a[i],cntclock_wise=d-a[i];
				if(clock_wise>359) clock_wise-=360;
				if(cntclock_wise<0) cntclock_wise+=360;
				dp[i][clock_wise]=1;
				dp[i][cntclock_wise]=1;
			}
		}
	}
	if(dp[n][0])cout<<"YES";
	else cout<<"NO";
}
