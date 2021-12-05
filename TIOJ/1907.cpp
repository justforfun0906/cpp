#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
int n;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)return a.first<b.first;
    else return a.second>b.second;
}
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin>>n;
	for(int num=0;num<n;++num){
		int t;
		cin>>t;
		pair<int, int>p[t];
		for(int i=0;i<t;i++){
			cin>>p[i].first>>p[i].second;
		}
		sort(p,p+t,cmp);
		int dp[t];
		for(int i=0;i<t;i++){
			dp[i]=1;
		}
		int max=1;
		for(int i=1;i<t;i++){
			for(int j=0;j<i;j++){
				if(p[i].second>p[j].second){
					if(dp[i]<dp[j]+1)dp[i]=dp[j]+1;
					if(dp[i]>max)max=dp[i];
				}
			}
		}
		cout<<max<<'\n';
	}
}
