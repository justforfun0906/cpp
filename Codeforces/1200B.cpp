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
	int c;cin>>c;
	while(c--){
		bool flag=1;
		int n,m,k;
		cin>>n>>m>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n-1;i++){
			if(a[i+1]-a[i]>k){
				int temp=(a[i+1]-a[i])-k;
				a[i]+=temp;
				m-=temp;
			}
			else if(a[i]-a[i+1]>-k){
				int temp = min(a[i], k-a[i+1]+a[i] );
				a[i]-=temp;
				m+=temp; 
			}
			if(m<0) flag=0;
		}
		if(flag)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}
