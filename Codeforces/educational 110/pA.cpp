#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a[4];
		for(int j=0;j<4;j++){
			cin>>a[j];
		}
		int b1,b2;
		if(a[0]>a[1]){
			b1=a[0];
		}
		else{
			b1=a[1];
		}
		if(a[2]>a[3]){
			b2=a[2];
		}
		else{
			b2=a[3];
		}
		sort(a,a+4);
		if(a[2]==b1&&a[3]==b2){
			cout<<"YES"<<endl;
		} 
		else if(a[2]==b2&&a[3]==b1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		} 
	}
} 
