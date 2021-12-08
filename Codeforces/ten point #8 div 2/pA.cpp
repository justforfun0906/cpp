#include<iostream>
using namespace std;
int main(){
	long long a,b,c,d,Qa,Qb;
	cin>>a>>b>>c>>d>>Qa>>Qb;
	if(c<Qa*a+Qb*b){
		cout<<-1;
	}
	else{
		c=c-Qa*a-Qb*b;
		cout<<c/d;
	}
} 
