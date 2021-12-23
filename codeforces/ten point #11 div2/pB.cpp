#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	long long c=__gcd(a,b);
	cout<<c<<' '<<a/c<<' '<<b/c;
}
