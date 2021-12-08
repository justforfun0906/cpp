#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a,b;
		long long count=0;
		cin>>a>>b;
		while(a>=3&b>=2){
			count+=1;
			a=a-3;
			b=b-2;
		}
		cout<<count<<endl;
	}
} 
