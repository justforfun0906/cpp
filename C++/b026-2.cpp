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
	int price[n];
	int temp=0;
	for(int i=0;i<n;i++){
		price[i]=temp+a[i];
		temp=price[i];
	}
	sort(price,price+n);
	for(int i=0;i<n;i++){
		cout<<price[i];
	}
	//cout<<price[n-1]-price[0];
} 
