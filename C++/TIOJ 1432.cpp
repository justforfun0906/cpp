#include<iostream>
#include<algorithm>
using namespace std;
int a,b;
int main(){
	while(cin>>a>>b&&a!=0&&b!=0){
		int d[a];
		for(int i=0;i<a;i++){
			cin>>d[i];
			if(i>0){
				d[i]+=d[i-1];
			}
		}
		int k=d[a-1];
		for(int i=0;i<a;i++){
			d[i]=max(d[i],k-d[i]);
		}
		cout<<*min_element(d,d+a)<<endl;
	}
}
