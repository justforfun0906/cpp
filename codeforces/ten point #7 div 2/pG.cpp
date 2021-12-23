#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long int mod=100000007;
	long long int moda=a%mod;
	long long int modb=b%mod;
	long long int modc=c%mod;
	long long int modd=d%mod;
	cout<<((int)(pow(moda,modd)%mod)*((int)pow(modd,moda)%mod)*((int)pow(modb,modc)%mod)*((int)pow(modc,modb)%mod)*((int)pow(modd,modb)%mod))%mod;    
} 
