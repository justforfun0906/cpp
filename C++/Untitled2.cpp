#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		m=m*2;
		int s=(m/2)-1;
		int b=s+2;
		int a[m];
		for(int j=0;j<m;j++){
			cin>>a[i];
		} 
		sort(a,a+m);
		int small[s];
		int big[b];
		for(int j=0;j<s;j++){
			small[j]=a[j];
		}
		for(int j=(m/2)-1;j<m;j++){
			big[j]=a[j];
		}
		int ans[m];
		int inda=0,indb=0;
		while(inda<m-2){
			ans[inda]=big[indb];
			inda+=1;
			ans[inda]=small[indb];
			inda+=1;
			indb+=1;
		}
		ans[m-2]=big[(m/2)-1];
		ans[m-1]=big[m/2];
		for(int j=0;j<m;j++){
			cout<<ans[j]<<' ';
		}
	}
} 
