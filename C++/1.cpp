#include<iostream>
using namespace std;
int main(){
	int a[5],max=0,min=0,x,y;
	for(int i=0;i<5;++i){
		cin>>a[i];
	}
	for(int i=0;i<5;++i){
		if(a[i]>max){
			max=a[i];
			x=i;
		}
	}
	min=max;
	for(int i=0;i<5;++i){
		if(a[i]<min){
			min=a[i];
			y=i;
		}
	}
	cout<<x<<','<<max<<','<<y<<','<<min;
} 
