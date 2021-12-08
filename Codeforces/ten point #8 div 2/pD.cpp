#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cnt[24];
	for(int i=0;i<24;i++){
		cnt[i]=0;
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		for(int j=a-1;j<b;j++){
			cnt[j]+=1;
		}
	}
	int max=cnt[0];
	for(int i=0;i<24;i++){
		if(cnt[i]>max){
			max=cnt[i];
		}
	}
	cout<<max;
}
