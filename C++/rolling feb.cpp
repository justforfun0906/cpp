#include<iostream>
using namespace std;
int main(){
	int a[3];
	a[0]=1;
	a[1]=1;
	int n;
	cin>>n;
	int cnt=0;
	while(cnt<n-2){
		a[2]=a[0]+a[1];
		a[0]=a[1];
		a[1]=a[2];
		cnt+=1;
	}
	cout<<a[2];
} 
