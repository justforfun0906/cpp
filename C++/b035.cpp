#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cnt+=(n-i-1)*a[i];
	}
	cout<<cnt<<"00";
} 
