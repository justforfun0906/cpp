#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int len;
int main(){
	cin>>len;
	int a[len];
	vector <int> temp;
	for(int i=0;i<len;i++){
		cin>>a[i];
		if(temp.empty()||a[i]>temp.back()){
			temp.push_back(a[i]);
		}
		else{
			*lower_bound(temp.begin(),temp.end(),a[i])=a[i];
		}
	}
	cout<<temp.size();
}
