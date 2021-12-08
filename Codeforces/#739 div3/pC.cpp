#include<iostream>
using namespace std;
long long arr[32005][2];
int main(){
	arr[1][0]=1;
	arr[1][1]=1;
	long long updis=1;
	long long downdis=3;
	for(int i=2;i<=32000;i++){
		arr[i][0]=arr[i-1][0]+updis;
		updis+=2;
		arr[i][1]=arr[i-1][1]+downdis;
		downdis+=2; 
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		for(int j=1;j<=32000;j++){
			if(a<=arr[j][1]&&a>=arr[j][0]){
				long long mid=(arr[j][0]+arr[j][1])/2;
				if(a==mid) cout<<j<<' '<<j<<'\n';
				else if(a<mid){
					cout<<j-(mid-a)<<' '<<j<<'\n';
				}
				else{
					cout<<j<<' '<<j-(a-mid)<<'\n';
				}
			} 
		}
	}
}
