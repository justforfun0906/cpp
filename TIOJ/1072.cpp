//code for fun
#include<bits/stdc++.h>
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
		if(n==0) break;
		priority_queue< pii >pq; 
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			pq.push(make_pair(b,a));
		}
		int cnt=0,now=0;
		while(!pq.empty()){
			now+=pq.top().ss;
			cnt=max(cnt,now+pq.top().ff);
			pq.pop();
		}
		cout<<cnt<<'\n';	
	}
}

