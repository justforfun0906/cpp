#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x:a) cin >> x;
	int ans = 1e18; 
	for(int i = 0; i < (1<<n); ++i){
		int x = 0, y = 0;
		for(int j = 0; j < n; ++j){
			if(i & (1<<j)) x += a[j];
			else y += a[j];
		}
		ans = min(abs(x - y), ans);
	}
	cout << ans << '\n';
}
