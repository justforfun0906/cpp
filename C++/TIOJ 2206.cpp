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
	faster;
	int n;
	cin>>n;
	int v[n+1];
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		while(b--){
			a=v[a];
		}
		cout<<a<<'\n';
	}
}

