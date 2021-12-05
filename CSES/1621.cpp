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
	int n;
	cin>>n;
	set<int> bag;
	int temp;
	cin>>temp;
	ll cnt=1;
	bag.insert(temp);
	for(int i=0;i<n-1;i++){
		cin>>temp;
		if(!bag.count(temp))cnt++;
		bag.insert(temp);
	}
	if(n==0) cout<<0;
	else cout<<cnt;
}

