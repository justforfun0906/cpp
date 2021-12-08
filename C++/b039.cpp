#include<iostream>
using namespace std;
bool xused[15];
int solution[15];
void print_solution(int solution[],int m){
	for(int i=0;i<m;i++){
		cout<<solution[i]<<' ';
	}
	cout<<endl;
}
void backtrack(int m,int y){
	if(y==m){
		print_solution(solution,m);
		return;
	}
	for(int i=0;i<m;i++){
		if(xused[i]==0){
			bool put=1;
			for(int j=1;j<=y;j++){
				if(i+j<m&&solution[y-j]==i+j+1){
					put=0;
				}
				if(i-j>=0&&solution[y-j]==i-j+1){
					put=0;
				}
			}
			if(put==1){
				xused[i]=1;
				solution[y]=i+1;
				backtrack(m,y+1);
				xused[i]=0;
			}		
		}
	}
}
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	backtrack(n,0);
} 
