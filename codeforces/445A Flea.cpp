//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	int n,m,jump;
	long long ans;
	cin>>n>>m>>jump;
	if(m<n) swap(m,n);
	if(m>2*jump&&n>2*jump){
		long long a=(m%jump)*(m/jump+1), b=(n%jump)*(n/jump+1);
		if(m%jump==0)
			a=m;
		else if((m-1)%jump==0)
			a=(m/jump+1);
		if(n%jump==0)
			b=n;
		else if((n-1)%jump==0)
			b=(n/jump+1);
		ans=a*b;
	}
	else if(m>2*jump&&n>jump)
		ans=(ll)(m-2*jump)*(n-jump)*2;
	else if(m>2*jump&&n<=jump)
		ans=(ll)(m-2*jump)*n;
	else if(m>jump&&n>jump)
		ans=(ll)(m-jump)*(n-jump)*4;
	else if(m>jump&&n<=jump)
		ans=(ll)(m-jump)*n*2;
	else if(m<=jump&&n<=jump)
		ans=(ll)m*n;
	cout<<ans;
}

