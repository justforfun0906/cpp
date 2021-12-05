//code for fun
#include<iostream>
#include<utility>
#include<algorithm>
#include<set>
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
	int man,shake,query;
	cin>>man>>shake>>query;
	set<pair <int ,int> > s;
	for(int i=0;i<shake;i++){
		int a,b;
		cin>>a>>b;
		if(b>a)
			swap(a,b);
		s.insert(make_pair(a,b));
	}
	for(int i=0;i<query;i++){
		int a,b;
		cin>>a>>b;
		if(b>a)
			swap(a,b);
		if(s.find(make_pair(a,b))!=s.end()){
			cout<<"yes"<<'\n';
		}
		else{
			cout<<"no"<<'\n';
		}
	}
}


