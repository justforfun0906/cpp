#include<iostream>
using namespace std;
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	int k[n];
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	int ans=0;
	bool tp=0;
	for(int i=0;i<n;i++){
		if(tp==0){
			if(k[i]==a){
				tp=1;
			}
			else{
				ans+=k[i];
			}
		}
		else{
			if(k[i]==b){
				tp=0;
			}
		}
	}
	cout<<ans;
}
