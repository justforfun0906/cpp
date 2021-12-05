#include<iostream>
#include<algorithm>
#include<utility>
#include<vector> 
using namespace std;
int n;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)return a.first<b.first;
    else return a.second>b.second;
}
int main(){
	cin.tie();cout.tie();
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int num=0;num<n;++num){
		int t;
		cin>>t;
		pair<int, int>p[t];
		for(int i=0;i<t;i++){
			cin>>p[i].first>>p[i].second;
		}
		sort(p,p+t,cmp);
		vector<int>temp;
		for(int i=0;i<t;i++){
			if(temp.empty()||p[i].second>temp.back()){
				temp.push_back(p[i].second);
			}
			else{
				*lower_bound(temp.begin(),temp.end(),p[i].second)=p[i].second;
			}
		}
		cout<<temp.size()<<'\n';
	}
}
