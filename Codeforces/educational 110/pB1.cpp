#include<iostream>
#include<algorithm>
using namespace std;
struct pp{
	int cnt;
	int ind;
};
pp p[26];
bool cmp(pp a,pp b){
	if(a.cnt==b.cnt){
		return a.ind<b.ind;
	}
	else{
		return a.cnt>b.cnt;
	}
}
int main(){
	string a;
	cin>>a;
	for(int i=0;i<26;i++){
		p[i].ind=i;
	}
	for(int i=0;i<a.length();i++){
		p[a[i]-'A'].cnt+=1;
	}
	sort(p,p+26,cmp);
	for(int i=0;i<26;i++){
		if(p[i].cnt!=0){
			cout<<char('A'+p[i].ind);
		}
	}	
}
