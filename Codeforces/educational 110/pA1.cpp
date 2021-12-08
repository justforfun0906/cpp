#include<iostream>
using namespace std;
int a[20][20];
int ans[20][20];
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			ans[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int find[4]={a[i-1][j], a[i+1][j], a[i][j-1], a[i][j+1]};
			if(a[i][j]==0){
				int num=4;
				int cnt=0;
				for(int s=0;s<4;s++){
					if(find[s]==0){
						num-=1;
					}
					else{
						cnt+=find[s];
					}
				}
				if(cnt!=0){
					ans[i][j]+=cnt/num;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
} 
