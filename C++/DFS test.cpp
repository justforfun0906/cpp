#include<iostream>
#include<vector>
using namespace std;
bool g[4][4];
bool visit[4];
int n,m;
int count=0;
void DFS(int i){
	cout<<"visiting "<<i+1<<endl;
    for (int j=0; j<4; j++)
        if (g[i][j] && !visit[j])
        {	
            visit[j] = true;    // 標記為已遍歷
            DFS(j);
        }
}
int main(){
	int p1, p2;
	while(cin>>p1>>p2){
		g[p1-1][p2-1]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}
	DFS(0);
	for(int i=0;i<4;i++){
		cout<<visit[i]<<' ';
	}
	
} 
