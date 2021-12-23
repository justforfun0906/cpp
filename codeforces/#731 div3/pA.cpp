#include<iostream>
#include<utility>
using namespace std;
int q;
int main(){
	cin>>q;
	for(int i=0;i<q;i++){
		int a1,a2,b1,b2,f1,f2;
		cin>>a1>>a2>>b1>>b2>>f1>>f2;
		int cnt,temp1=b1-a1,temp2=b2-a2;
		if(temp1<0)temp1=-temp1;
		if(temp2<0)temp2=-temp2;
		cnt=temp1+temp2;
		if(f1==a1&&f1==b1){
			if(a2>f2&&f2>b2){
				cnt+=2;
			}
			else if(b2>f2&&f2>a2){
				cnt+=2;
			}
		}
		else if(f2==a2&&f2==b2){
			if(a1>f1&&f1>b1){
				cnt+=2;
			}
			else if(b1>f1&&f1>a1){
				cnt+=2;
			}			
		}
		cout<<cnt<<'\n';
	}
}
