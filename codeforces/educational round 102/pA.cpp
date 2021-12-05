#include<iostream>
#include<algorithm>
using namespace std;
int cases,element,val;
int ans[2000];
int main(){
	bool les=0;
	int x,y;
	cin>>cases;
	for(int c=0;c<cases;c++){
		cin>>element>>val;
		int a[element];
		for(int i=0;i<element;i++){
			cin>>a[i];
		}
		for(int i=0;i<element;i++){
			if(a[i]<=val){
				ans[c]=2;
			}
			else{
				ans[c]=1;
			}
		}
		if(les==0){
			sort(a,a+element);
			if(a[0]+a[1]<=val){
				ans[c]=2;
			}
		}
	}
	for(int i=0;i<2000;i++){
		if(ans[i]==1){
			cout<<"NO"<<endl;
		}
		else if(ans[i]==2){
			cout<<"YES"<<endl;
		}
	}
} 
