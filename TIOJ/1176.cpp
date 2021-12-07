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
	stack<int> ans, cows;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		cows.push(temp);
	}
	int pre=cows.top();
	ans.push(0);
	cows.pop();
	for(int i=1;i<n;i++){
		if(cows.top()>pre) ans.push(ans.top()+1);
		else ans.push(1);
		pre=cows.top();
		cows.pop();
	}
	while(!ans.empty()){
		cout<<ans.top()<<'\n';
		ans.pop();
	}
}
