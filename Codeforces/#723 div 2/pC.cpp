#include<iostream>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int sum=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(sum>=0){
			sum+=a[i];
			cnt+=1; 
		}
	}
	cout<<cnt-1;
}
