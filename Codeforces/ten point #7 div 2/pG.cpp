#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long ans=1;
	ans*=pow(a,d);
	ans=ans%100000007;
	ans*=pow(d,a);
	ans=ans%100000007;
	ans*=pow(b,c);
	ans=ans%100000007;
	ans*=pow(c,b);
	ans=ans%100000007;
	ans*=pow(d,b);
	ans=ans%100000007;
	cout<<ans;
}
