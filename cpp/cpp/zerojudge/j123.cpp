#include<bits/stdc++.h>
using namespace std;
pair<int,int> k[5]={{4,1},{1,3},{2,2},{2,3},{3,2}};
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	int left=n,drop=0;
	while(n--){
		char type;
		cin>>type;
		int t=type-'A';
		int dis;
		cin>>dis;
		if((k[t].first+dis)>a){
			cout<<"drop!"<<'\n';
			drop++;
		}
		else{
			if((left-k[t].second)<0){
				cout<<"drop!"<<'\n';
				drop++;
		}
			else{
				cout<<"in! ";
				left+=k[t].second;
				cout<<"left= "<<left<<'\n';
			}
		}
	}
	cout<<left<<' '<<drop;
}

