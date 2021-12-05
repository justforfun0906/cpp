#include<iostream>
#include<stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int k=0;k<n;k++){
		int a;
		cin>>a;
		int b[a];
		stack <int> gi,oh; 
		for(int i=0;i<a;i++){
			cin>>b[i];
		}
		for(int i=0;i<a;i++){
			if(b[i]%2==0){
				oh.push(b[i]);
			}
			else{
				gi.push(b[i]);
			}
		}
		while(!oh.empty()){
			cout<<oh.top()<<' ';
			oh.pop();
		}
		while(!gi.empty()){
			cout<<gi.top()<<' ';
			gi.pop();
		}
		cout<<endl;
	}
} 
