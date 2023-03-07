#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long n,cnt=0;
		cin>>n;
		string s;
		cin>>s;
		vector<bool> ToDelete(n+5,0),Deleted(n+5,1);
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				ToDelete[i]=1;
				Deleted[i]=0;
			}
		}
		for(auto i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				if(ToDelete[j]==0)break;
				if(ToDelete[j]==1&&Deleted[j]==0){
					cnt+=i;
					Deleted[j]=1;
					//cout<<"delete "<<i<<'*'<<d<<" cost= "<<i<<'\n';
				}  	
			}
		}
		cout<<cnt<<'\n';
	}
}
