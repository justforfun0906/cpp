#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a<b)swap(a,b);
		int dis=a-b;
		if(c>(a-b)*2||a>(a-b)*2||b>(a-b)*2)cout<<-1<<'\n';
		else if(c+dis>(a-b)*2&&c-dis<1)cout<<-1<<'\n';
		else if(c+dis>(a-b)*2) cout<<c-dis<<'\n';
		else cout<<c+dis<<'\n';
		
	}
} 
