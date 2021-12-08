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
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a+4);
	int ans=0;
	ans+=a[2]+a[3]+a[0]*2+a[1]*2;
	cout<<ans;
}

