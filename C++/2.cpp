#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int A[b];
	for(int i=0;i<b;i++){
		cin>>A[i];
	}
	int B[a];
	for(int i=0;i<a;i++){
		B[i]=i+1;
	}
	for(int i=0;i<a;i++){
		bool out=1;
		for(int j=0;j<b;j++){
			if(i==A[j]){
				out=0;
			}
		}
		if (out==1){
			cout<<i<<' ';
		}
	}
} 
