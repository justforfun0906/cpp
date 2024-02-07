#include<stdio.h>
int m,n,ans=0;
int g[15][15];
int checkqueen(int x, int y);
int checkrook(int x, int y);
void dfs(int now_m, int now_n);
void print_graph(){
	printf("solution: %d\n", ans);
	for(int i=0;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			if(g[i][j]==0){
				printf("0");
			}
			if(g[i][j]==1){
				printf("Q");
			}
			if(g[i][j]==2){
				printf("R");
			}
		}
		printf("\n");
	}
}
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
void dfs(int now_q, int now_r){
	if(now_q + now_r == n+m){
		ans++;
		//print_graph();
		return;
	}
	//set queens first
	//for(int i=now_q+now_r;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			//empty = 0, queen = 1, rook = 2
			if(checkqueen(now_q+now_r,j)&&now_q<n){
				g[now_q+now_r][j] = 1;
				dfs(now_q+1,now_r);
				g[now_q+now_r][j] = 0;
			}
		}
	//}
	//then set rooks
	//for(int i=now_r+now_q;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			if(checkrook(now_q+now_r,j)&&now_r<m){
				g[now_q+now_r][j] = 2;
				dfs(now_q,now_r+1);
				g[now_q+now_r][j] = 0;
			}
		}
	//}
	return;
}
int checkqueen(int x, int y){
	for(int i=0;i<m+n;i++){
		if(g[x][i]!=0||g[i][y]!=0){
			return 0;
		}
	}
	for(int i=0;i<m+n;i++){
		if(x+i<m+n&&y+i<m+n&&g[x+i][y+i]!=0){
			return 0;
		}
		if(x-i>=0&&y-i>=0&&g[x-i][y-i]!=0){
			return 0;
		}
		if(x+i<m+n&&y-i>=0&&g[x+i][y-i]!=0){
			return 0;
		}
		if(x-i>=0&&y+i<m+n&&g[x-i][y+i]!=0){
			return 0;
		}
	}
	return 1;
}
int checkrook(int x, int y){
	for(int i=0;i<m+n;i++){
		if(g[x][i]!=0||g[i][y]!=0){
			return 0;
		}
	}
	for(int i=0;i<m+n;i++){
		if(x+i<m+n&&y+i<m+n&&g[x+i][y+i]==1){
			return 0;
		}
		if(x-i>=0&&y-i>=0&&g[x-i][y-i]==1){
			return 0;
		}
		if(x+i<m+n&&y-i>=0&&g[x+i][y-i]==1){
			return 0;
		}
		if(x-i>=0&&y+i<m+n&&g[x-i][y+i]==1){
			return 0;
		}
	}
	return 1;
}