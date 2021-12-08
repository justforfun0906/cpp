#include<iostream>
using namespace std;
int opt(int a,int b){
	int cnt=0;
	while(a!=0){
		a=a/b;
		cnt+=1;
	}
	return cnt;
}
int solve(int a,int b){
	int A,B;
	A=opt(a,b);
	B=opt(a,b+1);
	if(a==0){
		return 0;
	}
	if((a/b)==0){
		return 1;
	}
	if(opt(a,b)<opt(a,b+1)+1){
		a=a/b;
		return solve(a,b)+1;
	}
	else{
		b+=1;
		return solve(a,b)+1;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(b==1){
			b=2;
			cout<<solve(a,b)+1<<endl;
		}
		else{
			cout<<solve(a,b)<<endl;
		}
	}
}
