#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int k=0;k<n;k++){
		int l;
		cin>>l;
		char a[l];
		for(int i=0;i<l;i++){
			cin>>a[i];
		}
		int Mcnt=0,DnTcnt=0;
		for(int i=0;i<l;i++){
			if(DnTcnt==0&&a[i]=='T'){
				Mcnt+=1;
			}
			else if(a[i]=='M'&&Mcnt!=0){
				DnTcnt+=1;
				Mcnt-=1;
			}
			else if(a[i]=='T'){
				DnTcnt-=1;
			}
			else{
				Mcnt-=1;
			}
		}
		if(Mcnt==0&&DnTcnt==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
