#include<bits/stdc++.h>
using namespace std;
vector<vector <int> > g(100005);
int check[100005];
long long cnt=0;
void build(int node){
	if(node%2){
		for(int i=0;i<3;i++){
			int temp;
			cin>>temp;
			if(temp!=0){
				g[node].push_back(temp);
				build(temp);
			}
		}
	}
	else{
		for(int i=0;i<2;i++){
			int temp;
			cin>>temp;
			if(temp!=0){
				g[node].push_back(temp);
				build(temp);
			}
		}
	}
} 
void dfs(int node){
	for(int i=0;i<g[node].size();i++){
		if(check[g[node][i]]==0){
			check[g[node][i]]=1;
			cnt+=abs(node-g[node][i]);
			//cout<<abs(node-g[node][i])<<'\n';
			dfs(g[node][i]);
		}
	}
}
int main(){
	int k;
	cin>>k;
	build(k);
	dfs(k);
	cout<<cnt;
}

