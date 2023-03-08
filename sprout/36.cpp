#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	stack<int> steak;
	while(t--){
		int a;
		cin>>a;
		if(a==1){
			int b;
			cin>>b;
			steak.push(b);
		}
		else{
			if(steak.empty())cout<<"empty!"<<'\n';
			else{
				cout<<steak.top()<<'\n';
				steak.pop();
			}
		}
	}
}
