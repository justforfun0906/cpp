#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int query;
		cin>>query;
		int lA=0,lB=0;
		bool flagA=0,flagB=0;
		while(query--){
			int d,k;
			string str;
			cin>>d>>k>>str;
			if(d==1){
				for(auto a:str){
					if(a!='a')flagA=true;
					else lA+=k;//"a" count
				}
			}
			else if(d==2){
				for(auto a:str){
					if(a!='a')flagB=true;// if there's char other than "a" in string t
					else lB+=k;//"a" count
				}
			}
			if(flagB){
				cout<<"YES"<<'\n';
			}
			else if(!flagA&&lA<lB){//both string s and t are formed with only "a" and length of s is shorter than t
				cout<<"YES"<<'\n';
			}
			else{
				cout<<"NO"<<'\n';
			}
		}
	}
}

