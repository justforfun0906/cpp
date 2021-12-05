#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0||m==0)return 0;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		cout<<a[m-1]<<endl;
	}
}
