#include<iostream>
using namespace std;
int arr[1005];
int main(){
	int index=1;
	int num=1;
	while(index<=1000){
		if(num%10==3||num%3==0)num++;
		else{
			arr[index]=num;
			num++;
			index++;
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cout<<arr[a]<<'\n';
	}
} 
