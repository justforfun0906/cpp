#include<iostream>
using namespace std;
	long long a[100003];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char temp;
		cin>>temp;
		a[i]+=temp-'a'+1;
		a[i]+=a[i-1];
	}
	for(int i=0;i<m;i++){
		int r,l;
		cin>>r>>l;
		cout<<a[l]-a[r-1]<<endl;
	}
} 
