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
	int n;
	cin>>n;
	int cnt=0;
	while(n){
		if(n%2==1) cnt++;
		n=n/2;
	}
	if(cnt==0) cout<<1;
	else cout<<cnt;
}

