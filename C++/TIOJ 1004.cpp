#include<iostream>
using namespace std;
int k=1;
int n;
void jude(bool a[]){
	int kill=0;
	bool s=0;
	int i=0;
	while(kill<sizeof(a)){
		if(a[i]==1){
			if(s==0){
				s=1;
				if(i==sizeof(a)){
					i=1;
					for(int i=0;i<n;i++){
						if(a[i]==1){
							cout<<"1 ";
						}
						else{
							cout<<"0 ";
						}
					}
				}
				else{
					i+=1;
				}
			}
			else if(s==1){
				a[i]=0;
				s=0;
				if(i==sizeof(a)){
					i=1;
					for(int i=0;i<n;i++){
						if(a[i]==1){
							cout<<"1 ";
						}
						else{
							cout<<"0 ";
						}
					}
				}
				else{
					i+=1;
				}
			}
		}
		if(a[i]==0){
			if(i==sizeof(a)){
					i=1;
			}
				else{
					i+=1;
			}
		}
	}
}
int main(){
	cin>>n;
	bool a[n];
	for(int i=0;i<n;i++){
		a[i]=true;
	}
	jude(a);
	cout<<"done";
	for(int i=0;i<n;i++){
		if(a[i]==1){
			cout<<"1 ";
		}
		else{
			cout<<"0 ";
		}
	}
}
