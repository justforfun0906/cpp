#include<iostream>
#include<algorithm>
using namespace std;
int findInd(int a[],int k){
	for(int i=0;i<sizeof(a);i++){
		if(a[i]>k){
			return i;
		}
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long s=sizeof(a)/4;
	cout<<s-findInd(a,k);
}
