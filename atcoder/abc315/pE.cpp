#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > g(200005);
vector<bool> check(200005, 0);
vector<int> ans;
void dfs(int n, int node){
	if(g[node].empty()){// leaf node
		if(check[node]==0){
			ans.push_back(node);
			check[node]=1;
		}
		return;
	}
	else{
		for(int i=0;i<g[node].size();i++){
			if(check[g[node][i]]==0)dfs(n, g[node][i]);
		}
		check[node]=1;
		ans.push_back(node);
		return;
	}
}
int main(){
	int n; 
	cin>>n;
	for(int i=0;i<n;i++){
		int m; cin>>m;
		for(int j=0;j<m;j++){
			int temp; cin>>temp;
			g[i+1].push_back(temp);
		}
	}
	dfs(n, 1);
	for(auto x:ans)if(x!=1)cout<<x<<' ';
}