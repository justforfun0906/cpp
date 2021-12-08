//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
struct boss{
	int x,y,s,t;
};
int visit[105][105],bomb[105][105];
bool die[505];
int die_cnt=0;
int main(){
	faster;
	int n,m,k;
	cin>>n>>m>>k;
	boss move[k];
	int cnt=0;
	for(int i=0;i<k;i++){
		cin>>move[i].x>>move[i].y>>move[i].s>>move[i].t;
		visit[move[i].x][move[i].y]=1;
	}
	int alive=k;
	while(alive){
		for(int i=0;i<k;i++){
			if(!die[i]){
				//puts("yo");
				//cout << move[i].x << " " << move[i].y << "\n"; 
				bomb[move[i].x][move[i].y]=1;
				
				move[i].x+=move[i].s;
				move[i].y+=move[i].t;
				//cout<<"boss "<<i<<" move to"<<move[i].x<<' '<<move[i].y<<"\n";
				
				if(move[i].x>=n||move[i].x<0||move[i].y>=m||move[i].y<0){
					//cout<<"boss "<<i<<" out of border and died"<<"\n";
					die[i]=1;
					alive--;
				}
				
				else if(visit[move[i].x][move[i].y]==1){
					bomb[move[i].x][move[i].y]=0;
					//cout<<"boss "<<i<<" step on bomb and died"<<"\n";
					die[i]=1;
					alive--;
				}
			}
		}
		int temp=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					visit[i][j]=bomb[i][j];
					//cout<<visit[i][j]<<' ';
					if(visit[i][j]==1) temp++;
				}
				//cout<<'\n';
			}
		cnt=temp;
	}
	cout<<cnt;
}

