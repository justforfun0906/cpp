#include<iostream>
#include<string>
using namespace std;
string a,b,c;
int main(){
	int ia=0;
	int ib=0;
	int ic=0;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	for(int i=0;i<100;i++){
		if(a[i]>='0'){
			ia+=a[i]-'0';
		}
	}
	for(int i=0;i<100;i++){
		if(b[i]!=' '){
			ib+=b[i]-'0';
		}
	}
	for(int i=0;i<100;i++){
		if(c[i]!=' '){
			ic+=c[i]-'0';
		}
	}
	cout<<ia<<' '<<ib<<' '<<ic; 
} 
