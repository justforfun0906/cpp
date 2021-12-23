//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
bool check[200005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int temp;
		cin>>temp;
		check[temp]=1;
	}
	for(int i=1;i<=n;i++){
		if(!check[i]){
			cout<<i;
		}
	}
}

