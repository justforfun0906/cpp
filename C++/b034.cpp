#include<iostream>
using namespace std;
int main(){
	int a;
	int count=0;
	cin>>a;
	while(a!=0){
		if(a>=10000){
			a=a-10000;
			count+=1;
		}
		else if(a<10000&&a>=5000){
			a-=5000;
			count+=1;
		}
		else if(5000>a&&a>=1000){
			a-=1000;
			count+=1;
		}
		else if(1000>a&&a>=500){
			a-=500;
			count+=1;
		}
		else if(500>a&&a>=100){
			a-=100;
			count+=1;
		}
		else if(100>a&&a>=50){
			a-=50;
			count+=1;
		}
		else if(50>a&&a>=10){
			a-=10;
			count+=1;
		}
		else if(10>a&&a>=5){
			a-=5;
			count+=1;
		}
		else if(5>a&&a>=1){
			a-=1;
			count+=1;
		}
	}
	cout<<count;
} 
