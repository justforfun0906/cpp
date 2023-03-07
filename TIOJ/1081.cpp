#include<bits/stdc++.h>
using namespace std;
short dx[8]={1,1,1,0,0,-1,-1,-1};
short dy[8]={0,1,-1,-1,1,1,0,-1};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	short n,m;
	while(cin>>n>>m&&(n!=0&&m!=0)){
		queue<pair<int, int> > bfs;
		string s[n+1];
		for(short i=0;i<n;i++)cin>>s[i];
		int cnt=0;
		bool arr[n+5][m+5];
		memset(arr,0,sizeof(arr));
		for(short i=1;i<=n;i++){
			for(short j=1;j<=m;j++) arr[i][j]=s[i-1][j-1]-'0';
		}
		for(short i=1;i<=n;i++){
			for(short j=1;j<=m;j++){
				if(arr[i][j]){
					cnt++;
					bfs.push(make_pair(i,j)) ;
					arr[i][j]=0;
				}
				while(!bfs.empty()){
					short tx=bfs.front().first;
					short ty=bfs.front().second;
					bfs.pop();
					for(short i=0;i<8;i++){
						if(arr[tx+dx[i]][ty+dy[i]]){
							bfs.push(make_pair(tx+dx[i],ty+dy[i]));
							arr[tx+dx[i]][ty+dy[i]]=0;
						} 
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
