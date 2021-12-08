#include<iostream>
using namespace std;
int main(){
	long long a,b;
	while(cin>>a>>b){
			long long sum=0;
	if(b>a)swap(a,b);
	while(a){
		if(b>a){
			swap(a,b);
		}
		sum+=a/b;
		a=a%b;
	}
	cout<<sum<<endl;
	}

} 
