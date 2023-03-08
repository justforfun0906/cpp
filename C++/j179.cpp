#include<bits/stdc++.h>
using namespace std;
int solve(int num){
		if(num/1000){
			int a[4];
			for(int i=0;i<4;i++){
				a[i]=num%10;
				num/=10;
			}
			int l=a[2]*a[3];
			int r;
			if(a[1]==0){
				r=a[0];
			}
			else r=a[1]*a[0];
			if(r/10) num=l*100+r;
			else num=l*10+r;
			//cout<<num<<'\n';
			solve(num);
		}
		else if(num/100){
			int a[3];
			for(int i=0;i<3;i++){
				a[i]=num%10;
				num/=10;
			}
			int l=a[1]*a[2];
			int r=a[1]*a[0];
			if(r/10){
				num=l*100+r;
			}
			else{
				num=l*10+r;
			}
			//cout<<num<<'\n';
			solve(num);
		}
		else if(num/10){
			int r=num%10;
			num/=10;
			int l=num%10;
			num/=10;
			num=l*r;
			//cout<<num<<'\n';
			solve(num);
		}
		else return num;
}
int main(){
	int num;
	cin>>num;
	cout<<solve(num);
} 
