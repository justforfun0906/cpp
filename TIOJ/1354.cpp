#include<iostream>
using namespace std;
int main(){
	int time;
	cin>>time;
	for(int k=0;k<time;k++){
		int n;
		cin>>n;
		int a[n+1][4];
		for(int i=0;i<=n;i++){
			for(int j=0;j<4;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<4;i++){
			a[1][i]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=0;j<4;j++){
				a[i][j]=a[i-1][0]+a[i-1][1]+a[i-1][2]+a[i-1][3]-a[i-1][j];
			}
		}
		cout<<a[n][0]<<endl;
	}
}
 
