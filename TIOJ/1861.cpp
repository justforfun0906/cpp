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
	while(cin>>n){
		priority_queue<int , vector<int>, greater<int> > loli;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			loli.push(temp);
		}
		int temp=0;
		long long ans=0;
		while(loli.size()){
			if(temp==0){
				temp=loli.top();
				loli.pop();
			}
			else{
				temp+=loli.top();
				ans+=temp;
				loli.pop();
				loli.push(temp);
				temp=0;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
}

