#include<bits/stdc++.h>
#include <numeric>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string times;
		int min;
		cin>>times>>min;
		int H,M,originH,originM,cnt=0;
		H=(times[0]-'0')*10+(times[1]-'0');
		M=(times[3]-'0')*10+(times[4]-'0');
		int rev=(M%10)*10+M/10;
			if(rev==H){
				cnt++;
		}
		originH=H;
		originM=M;
		M+=min;
		H+=M/60;
		M=M%60;
		H=H%24;
		//cout<<"origin time= "<<originH<<' '<<originM<<'\n'; 
		while(originH!=H||originM!=M){
			//cout<<H<<' '<<M<<'\n';
			int rev=(M%10)*10+M/10;
			if(rev==H){
				cnt++;
			}
			M+=min;
			H+=M/60;
			M=M%60;
			H=H%24;
		}
		cout<<cnt<<'\n';
	}
}
