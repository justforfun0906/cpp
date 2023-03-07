#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int ans2;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool check(int n,int mid){
	int dis[n+5][n+5];
	for(int i=0;i<n+5;i++){
		for(int j=0;j<n+5;j++){
			dis[i][j]=1e9;
		}
	}
	dis[0][0]=0;
	queue<pair<int, int>> bfs;
	bfs.push({0,0});
	while(bfs.size()){
		int x=bfs.front().first;
		int y=bfs.front().second;
		bfs.pop();
		for(int i=0;i<4;i++){
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(ty>=0&&ty<n&&tx>=0&&tx<n){
				if(abs(a[x][y]-a[tx][ty])<=mid){//walkable
					if(dis[tx][ty]>dis[x][y]+1){//can relax
						dis[tx][ty]=dis[x][y]+1;
						bfs.push(make_pair(tx,ty));
					}
				}
			}
		}
	}
	if(dis[n-1][n-1]<1e9){
		ans2=dis[n-1][n-1];
		return 1;
	}
	else return 0;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int maxh=0,minh=1e9;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(maxh<a[i][j])maxh=a[i][j];
			if(minh>a[i][j])minh=a[i][j];
		}
	}
	int r=maxh-minh+1, l=0;
	while(l<r-1){
		int mid=(r+l)/2;
		if(check(n,mid)==1){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	cout<<r<<'\n';
	cout<<ans2;
}

