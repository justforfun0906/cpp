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
	double pi=3.141592653589;
	double ans=0;
	long long allm=0;
	long long n; cin>>n;
	vector<long long> x(n);
	vector<bool> used_x(1e9);
	vector<long long> y(n);
	vector<bool> used_y(1e9);
	for(long long i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i]!=x[j]){
				allm+=(x[i]-x[j])*(x[i]-x[j]);
				ans+=allm*(pi/4);
				allm=0;
			} 
			if(y[i]!=y[j]){
				allm+=(y[i]-y[j])*(y[i]-y[j]);
				ans+=allm*(pi/4);
				allm=0;
			}
		}
	}
	cout<<setprecision(9)<<fixed<<ans;
}

