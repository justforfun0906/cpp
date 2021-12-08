#include <iostream>
#include <string>
using namespace std;
int di[10];
int main(){
	int m;
	cin>>m;
	while(m--){
		di[0]=0;
		for(int i=1;i<10;++i){
			di[i]=di[i-1]*10+1;
		}
		string s;
		cin>>s;
		int digit=s.size();
		int k=0;
		for(int i=0;i<digit;++i){
			k=k*10+(s[i]-'0');
		}
		for(int i=digit;i>1;--i){
			k%=di[i];
		}
		if(k==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
