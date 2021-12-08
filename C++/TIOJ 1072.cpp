//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
bool cmp(pii a, pii b){
	return a.ss>b.ss; 
}
int main(){
	faster;
	int n;
	cin>>n;
	vector< pii >dinner(n);
	for(int i=0;i<n;i++){
		cin>>dinner[i].ff>>dinner[i].ss;
	}
	sort(dinner.begin(),dinner.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<dinner[i].ff<<' '<<dinner[i].ss<<'\n'; 
	}
	int cnt=0,now=0;
	for(int i=0;i<n;i++){
		now+=dinner[i].ff;
		cnt=max(cnt,now+dinner[i].ss);
	}
	cout<<cnt;
}

