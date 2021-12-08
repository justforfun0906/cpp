#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		int k;
		cin>>k;
		int a[k];
		for(int i=0;i<k;i++){
			cin>>a[i];
		}
		int min=*min_element(a,a+k);
		int cnt=0;
		for(int i=0;i<k;i++){
			if(a[i]==min){
				cnt+=1;
			} 
		}
		cout<<k-cnt<<endl;
	}
} 
