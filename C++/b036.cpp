#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> v;
bool compare(int a,int b){
	return a>b;
}
int solve(int n,vector<int> v){
	int cnt;
	while(v.size()!=1){
		int size=v.size();
		int tmp=v[size-1]+v[size-2];
		cnt+=tmp;
		v.pop_back();
		v.pop_back();
		v.push_back(tmp);
		sort(v.begin(),v.end(),compare);
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end(),compare);
	cout<<solve(n,v);
}
 
