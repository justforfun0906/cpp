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
	stack<long long> cows;
	for(long long i=0;i<n;i++){
		long long temp;
		cin>>temp;
		cows.push(temp);
	}
	long long pre=1e9;
	int cnt=0;
	stack<int> ans;
	ans.push(0);
	cows.pop();
	while(cows.size()){
		if(cows.top()<=pre){
			ans.push(1);
			cnt=1;
			pre=cows.top();
			cows.pop();
		}
		else{
			ans.push(cnt);
			cnt++;
			pre=cows.top();
			cows.pop();
		}
	}
	while(ans.size()){
		cout<<ans.top()<<'\n';
		ans.pop();
	}
}

