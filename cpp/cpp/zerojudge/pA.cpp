#include<iostream>
using namespace std;
int main(){
	int q;
	cin>>q;
	while(q--){
		int N,h1,h2,h3;
	cin>>N;
	int a=N%3;
	if(a==0){
		h1=((N-3)/3)+1;
		h2=((N-3)/3)+2;
		h3=(N-3)/3;
	}
	else if(a==1){
		h1=((N-4)/3)+1;
		h2=((N-4)/3)+3;
		h3=(N-4)/3;
	}
	else{
		h1=((N-5)/3)+2;
		h2=((N-5)/3)+3;
		h3=(N-5)/3;
	}
	cout<<h1<<' '<<h2<<' '<<h3<<'\n';
	}
}