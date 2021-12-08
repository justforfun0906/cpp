#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		string a;
		cin>>a;
		int cnt=0;
		for(int j=0;j<l;j++){
			if(a[j]=='0'){
				cnt+=1;
			}
		}
		if(cnt==0){
			cout<<"DRAW"<<endl;
		}
		else if(cnt==1){
			cout<<"BOB"<<endl;
		} 
		else if(cnt%2==0){
			cout<<"BOB"<<endl;
		}
		else{
			cout<<"ALICE"<<endl;
		}
	}
}
