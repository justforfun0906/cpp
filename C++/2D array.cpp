#include<iostream>
using namespace std;
void function(int a[][6]){
	cout<<"OK";
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	function(a);
}
