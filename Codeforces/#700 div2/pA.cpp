#include<iostream>
using namespace std;
string game(string a){
	for(int i=0;i<a.length();i++){
		if(i%2==0){
		//alice turn
			if(a[i]=='a'){
				a[i]='b';
				//cout<<a;
			}
			else{
				a[i]='a';
				//cout<<a;
			}
		}
		else if(i%2==1){
		//bob turn
			if(a[i]=='z'){
				a[i]='y';
				//cout<<a;
			}
			else{
				a[i]='z';
				//cout<<a;
			}
		}
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		cout<<game(a)<<endl;
	} 
} 
