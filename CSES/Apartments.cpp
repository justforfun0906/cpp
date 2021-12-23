#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
bool check[200005];
int main(){
	faster;
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<m;i++) cin>>b[i];
	sort(b,b+m);
	for(int i=0;i<m;i++){
		int find=lower_bound(a,a+n,b[i])-&a[0];
		if(!check[find]&&a[find]-b[i]<=2*k){
			check[find]=1;
			cnt++;
		}
	}
	cout<<cnt;
}

