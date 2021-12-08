#include<iostream>
using namespace std;
 int main(){
 	int n;
 	cin>>n;
	if(n<=8){
		cout<<(n-1)*(n-2)/2;
	} 	
	else if(n>=9&&n<=14){
		cout<<21*n-83-(n*n);
	}
	else{
		cout<<(19-n)*(20-n)/2;
	}
} 
