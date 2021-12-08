//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	faster;
	int n;
	cin>>n;
	if (n==1) cout<<1;
	else if(n<4) cout<<"NO SOLUTION";
	else{
		for(int i=1;i<=n;i++){
			if(i%2==0) cout<<i<<' ';
		}
		for(int i=1;i<=n;i++){
			if(i%2==1) cout<<i<<' ';
		}
	} 
}

