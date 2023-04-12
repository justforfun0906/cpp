#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a;
		cin>>a;
		int cha[26];
		for(int i=0;i<26;i++)cha[i]=-1;
		bool flag=1;
		for(int i=0;i<n;i++){
			if(cha[a[i]-'a']==-1)cha[a[i]-'a']=i%2;
			else if(cha[a[i]-'a']!=i%2)flag=0;
		}
		if(flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}
