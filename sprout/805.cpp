#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,x,y;
	cin>>a>>x>>y;
	long long sum=0;
	sum+=x*(a/60);
	sum+=y*(a%60);
	cout<<sum<<'\n';
}
