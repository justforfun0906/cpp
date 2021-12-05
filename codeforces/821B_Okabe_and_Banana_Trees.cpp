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
	int m,b;
	cin>>m>>b;
	int xlim=m*b;
	long long max = 0;
	for(int x=0;x<=m*b;x++){
		float tx=x;
		float lim=-(tx/m)+b;
		if(lim==(int)lim){
			ll start=(lim*(lim+1))/2;//y axis number sum
			ll ans=start+(start+x*(lim+1));
			ans=ans*(x+1)/2;
			if(ans>max) max=ans;		
		}
	}
	cout<<max;
}

