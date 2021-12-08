#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		while(1){
			if(a<0){
				cout<<"NO"<<endl;
				break;
			}
			else if(a%11==0){
				cout<<"YES"<<endl;
				break;
			}
			a-=111;
		}
	}
} 
