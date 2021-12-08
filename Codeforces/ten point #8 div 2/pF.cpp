#include<iostream>
using namespace std;
void shit(string a,string b){
		getline(cin,a);
		getline(cin,b);
		string va,vb;
		for(int i=0;i<a.length();i++){
			if(a[i]!=' '){
				va+=a[i];
			}
		}
		for(int i=0;i<b.length();i++){
			if(b[i]!=' '){
				vb+=b[i];
			}
		}
		bool right=1;
		bool AC=1;
		for(int i=0;i<va.length();i++){
			if(va[i]!=vb[i]){
				right=0;
			}
		}
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				AC=0;
			}
		}
		if(AC==1){
			cout<<"Accepted"<<endl;
		}		
		else if(AC!=1&&right==1){
			cout<<"Presentation Error"<<endl;
		}
		else if(AC==0&&right==0){
			cout<<"Wrong Answer"<<endl;
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string a,b;
		shit(a,b);
	}
	 
}
