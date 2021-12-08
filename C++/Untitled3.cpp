#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int time=0;time<n;time++){
		int m;
		cin>>m;
		int a[m],b[m];
		int temp[2*m];
		for(int i=0;i<2*m;i++){
			cin>>temp[i];
		} 		
		sort(temp,temp+2*m);
		for(int i=0;i<m;i++){
			cout<<temp[i]<<' '<<temp[2*m-i-1]<<' ';
		}
		cout<<endl;
	}
} 
