#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
char k[100];
string L1,L2,L3;
int sum(string a){
	int ans=0;
	for(int i = 0;i<a.length();i++){
		if(a[i]!=' '){
			ans+=a[i]-'0';		
		}
	}
	return ans;
}
int main(){
	getline(cin,L1);
	getline(cin,L2);
	getline(cin,L3);	
	int arr[3]={sum(L1),sum(L2),sum(L3)};
	cout<<(max_element(arr,arr+3)-arr)+1<<' '<<*max_element(arr,arr+3);
} 
