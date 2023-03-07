#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,init;
		cin>>n>>init;
		int slime[n+1];
		for(int i=1;i<=n;i++)cin>>slime[i];
		long long health=slime[init];
		stack<int> left, right;
		for(int i=1;i<init;i++)left.push(slime[i]);
		for(int i=n;i>init;i--)right.push(slime[i]);
		while(!left.empty()&&!right.empty()){
			if(left.top()>right.top()){
				health+=left.top();
				left.pop();	
			}
			else if(right.top()>left.top()){
				health+=right.top();
				right.pop();
			}
			else{
				if(right.size()<left.size()){
					health+=right.top();
					right.pop();
				}
				else{
					health+=left.top();
					left.pop();
				}
			}
			if(health<=0){
				cout<<"NO"<<'\n';
				break;
			}
		}
		if(health>0)cout<<"YES"<<'\n';
	}
}

