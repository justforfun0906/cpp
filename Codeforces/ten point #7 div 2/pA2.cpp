#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a,b,ansa,ansb;
		cin>>a>>b;
		ansa=a/3;
		ansb=b/2;
		if(ansa>ansb){
			cout<<ansb<<endl;
		}
		else{
			cout<<ansa<<endl;
		}
	}
}
