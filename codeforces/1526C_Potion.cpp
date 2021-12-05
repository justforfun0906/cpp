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
	priority_queue<long long,vector<long long>,greater<ll> >pq;
	int n;
	cin>>n;
	long long temp=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		temp+=a;
		pq.push(a);
		while(temp<0){
			temp-=pq.top();
			pq.pop();
		}
	}
	cout<<pq.size();
}

