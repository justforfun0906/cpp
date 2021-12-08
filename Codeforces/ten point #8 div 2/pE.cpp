#include<iostream>
#include<stack> 
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	stack<int> sa,sb;
	for(int i=0;i<a.length();i++){
		sa.push(a[i]-'0');
	}
	for(int i=0;i<b.length();i++){
		sb.push(b[i]-'0');
	}
	long long aa[10],ab[10];
	for(int i=0;i<10;i++){
		aa[i]=0;
		ab[i]=0;
	}
	while(sa.empty()!=1){
		aa[sa.top()]+=1;
		sa.pop();
	}
	while(sb.empty()!=1){
		ab[sb.top()]+=1;
		sb.pop();
	}
	bool fire=1;
	for(int i=0;i<10;i++){
		if(aa[i]>0&&ab[i]>0){
			fire=0;
		}
	}  
	if(fire==1){
		cout<<"No"; 
	}
	else{
		cout<<"Yes";
	} 
}
