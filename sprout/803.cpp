#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	float average=0;
	for(int i=0;i<10;i++){
		cin>>a[i];
		average+=a[i];
	}
	average/=10;
	float mu=0;
	for(int i=0;i<10;i++){
		mu+=(a[i]-average)*(a[i]-average);
	}
	mu/=10;
	cout<<average<<" "<<mu<<'\n';
} 
