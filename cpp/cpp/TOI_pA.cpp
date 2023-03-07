#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		if(a[i]<=i+1){
			cout<<i+1;
			break;
		}
	}
}
