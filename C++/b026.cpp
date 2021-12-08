#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],sum[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i==0){
			sum[i]=a[i];
		} 
		else{
			sum[i]=sum[i-1]+a[i];
			if(sum[i]<0){
				sum[i]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<sum[i]<<' ';
	}
	cout<<endl;
	sort(sum,sum+n);
	cout<<sum[n-1];
	
}
