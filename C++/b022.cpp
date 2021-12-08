#include<iostream>
using namespace std;
long long cnt;
int fib(int n){
	cnt++;
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}
int main(){
	int k;
	cin>>k;
	cout<<fib(k);
	cout<<' ';
	cout<<cnt;
}
