#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second)return a.first < b.first;
	else return a.second < b.second;
}

int main(){
	int n;
	cin>>n;
	vector< vector< pair<int, int> > > arr(37);//<person, bet>
	for(int i=1;i<=n;i++){
		int bet; cin>>bet;
		for(int j=0;j<bet;j++){
			int k; cin>>k;
			arr[k].push_back(make_pair(i, bet));
		}
	}
	int outcome; cin>>outcome;
	sort(arr[outcome].begin(), arr[outcome].end(), cmp);
	if(arr[outcome].size()==0){
		cout<<0;
	}
	else{
		int b = arr[outcome][0].second;
		vector<int> answer;
		int cnt=0;
		for(auto x:arr[outcome]){
			if(x.second==b){
				cnt++;
				answer.push_back(x.first);
			}
		}
		cout<<cnt<<'\n';
		for(auto x:answer)cout<<x<<' ';
	}
}
