#include<iostream>
using namespace std;
int find(int n, int a[], int len){
	int cnt=0;
	int sum=0;
	for(int i=0;i<len;i++){
		if(sum+a[i]<=n){
			sum+=a[i];
		}
		else{
			sum=a[i];
			cnt+=1;
		}
	}
	return cnt;
}
int main(){
	int len,heavy;
	cin>>len>>heavy;
	int a[len];
	for(int i=0;i<len;i++){
		cin>>a[i];
	}
	int n;
	cin>>n;
	cout<<find(n,a,len);
	
}
