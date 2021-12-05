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
	long long guest;
	int clerk;
	cin>>guest>>clerk;
	priority_queue <long long ,vector<int> , greater<long long> > make_time(clerk,0); 
	vector <int> v (guest);
	for(long long i=0;i<guest;i++){
		cin>>v[i];
	}
	for(long long i=0;i<guest;i++){
		long long temp=make_time.top();
		make_time.pop();
		temp+=v[i];
		make_time.push(temp);
	}
	for(int i=0;i<clerk-1;i++){
		make_time.pop();
	}
	cout<<make_time.top();
}

