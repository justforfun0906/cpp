#include<stdio.h>
int m,n,ans=0;
int g[15][15];
int checkqueen(int x, int y);
int checkrook(int x, int y);
void dfs(int now_m, int now_n);
int main(){
	while(scanf("%d %d",&n, &m)!=EOF){
		ans = 0;
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				g[i][j] == 0;
			}
		}
		dfs(0,0);
		printf("%d\n",ans);
	}
}
void dfs(int now_m, int now_n){
	if(now_n + now_m == n+m){
		ans++;
		return;
	}
	//set queens first
	for(int i=0;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			//empty = 1, queen = 2, rook = 3
			if(checkqueen(i,j)){
				g[i][j] = 2;
				dfs(now_m+1,now_n);
				g[i][j] = 1;
			}else{
				g[i][j] = 1;
				dfs(now_m, now_n);
			}
		}
	}
	//then set rooks
	for(int i=0;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			if(checkrook(i,j)){
				g[i][j] = 3;
				dfs(now_m,now_n+1);
				g[i][j] = 1;
			}else{
				g[i][j] = 1;
				dfs(now_m,now_n);
			}
		}
	}
}