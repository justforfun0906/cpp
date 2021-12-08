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
	long long n;
	cin>>n;
	long long h[n];
	long long p[n];
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	sort(h,h+n);
	for(int i=0;i<n-1;i++){
		p[i]=h[i+1]-h[i];
	} 
	p[n-1]=h[n-1];
	long long minp=*min_element(p,p+n);
	long long minh=*min_element(h,h+n);
	if(minp<minh)cout<<minp;
	else cout<<minh;
}

