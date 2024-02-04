#include<stdio.h>
int m,n;
int g[15][15];
int dfs(int now_m, int now_n);
int main(){
	while(scanf("%d %d",&n, &m)!=EOF){
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				g[i][j] == 0;
			}
		}
		printf("%d\n",dfs(0,0));
	}
}
int dfs(int now_m, int now_n){
	for(int i=0;i<m+n;i++){
		for(int j=0;j<m+n;j++){
			
		}
	}
}