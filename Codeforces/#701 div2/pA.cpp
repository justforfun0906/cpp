#include<iostream>
using namespace std;
int a,b;
int A(int a,int b){
	a=a/b;
	a=a/b;
	return a;
}
int B(int a,int b){
	a=a/b;
	return a;
}
int solve(int a,int b){
	if(a==0){
		return 0;
	}
	if(a/b==0){
		return 1;
	}
	else if(A(a,b)<a/(b+1)){
		cout<<"A :"<<a<<' '<<b<<endl;
		return solve(A(a,b),b)+2;
	}
	else{
		b+=1;
		cout<<"B :"<<a<<' '<<b<<endl;
		return solve(a,b)+1;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		cout<<solve(a,b)<<endl;;
	}
} 
