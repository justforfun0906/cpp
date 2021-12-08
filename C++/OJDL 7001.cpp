//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
vector<vector<long long> > g(10005,1e11); 
long long dis[10005];
int main(){
	faster;
	int n,m;
	cin>>n>>m;
	for(int i=2;i<=n){
		dis[i]=1e11;
	}
	dis[1]=0;
	for(int i=1;i<=m;i++){
		long long a,b,cost;
		cin>>a>>b>>cost;
		if(a==1){
			dis[b]=cost;
		}
		if(b==1){
			dis[a]=cost;
		}
		g[a][b]=cost;
		g[b][a]=cost;
	}
	for(int i=2;i<=n;i++){
		if(dis!=1e11){
			
		}
	}
}

