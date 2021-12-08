#include<iostream>
using namespace std;
int main(){
	int num;
	cin>>num;
	for(int f=0;f<num;f++){
		string a;
		cin>>a;
		int cnt=0;
		for(int s=0;s<a.length();s++){
			bool start=1;
			bool last;
			bool plus=1;
			for(int i=s;i<a.length();i++){
				if(plus==1){
					if(start==1){
						if(a[i]=='?'){
							cnt+=1;
						}
						else if(a[i]=='1'){
							cnt+=1;
							last=1;
							start=0;
						}
						else{
							cnt+=1;
							last=0;
							start=0;
						}
					}
					else{
						if(a[i]=='1'){
							if(last==0){
								last=1;
								cnt+=1;
							}
							else{
								plus=0;
							}
						}
						else if(a[i]=='0'){
							if(last==1){
								last=0;
								cnt+=1;
							}
							else{
								plus=0;
							}
						}
						else{
							last=!last;
							cnt+=1;
						}
					}
					if(a[i]=='0'&&start==0){
						if(last==1){
							cnt+=1;
							last=0;
						}
						else{
							plus=0;
						}
					}
				}
			}		
		}
	cout<<cnt<<endl;
	}
} 
