//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int a[105];
bool dp[105][100005];
int main(){
	faster;
	int m,n;
	cin>>m>>n;
	while(m--){
		for(int i=0;i<105;i++){
			a[i]=0;
		}
		for(int i=0;i<105;i++){
			for(int j=0;j<100005;j++){
				dp[i][j]=0;
			}
		}
		long long target=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			target+=a[i];
		}
		if(target%2){
			cout<<"No"<<'\n';
			continue;
		}
		target/=2;
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=target-a[i];j++){
				if(dp[i-1][j]){
					dp[i][j+a[i]]=1;
					dp[i][j]=1;
				}
			}
		}
		if(dp[n][target])cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	} 
}

