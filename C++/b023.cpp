#include<iostream>
using namespace std;
void hanoi(int ring,int one,int two,int three){
	if(ring==1){
		cout<<"Ring "<<ring<<" from "<<one<<" to "<<three<<endl;
	}
	else{
		hanoi(ring-1,one,three,two);
		cout<<"Ring "<<ring<<" from "<<one<<" to "<<three<<endl;
		hanoi(ring-1, two, one, three);
	}
}
int main(){
	int n;
	cin>>n;
	hanoi(n,1,2,3);
}
