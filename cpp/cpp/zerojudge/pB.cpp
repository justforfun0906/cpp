#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		int a[n],b[n],d[n];
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		bool ok=1;
		for(int i=0;i<n;i++){
			d[i]=a[i]-b[i];
			if(d[i]<0)ok=0;
		}
		if(ok&&n>1){
			for(int i=0;i<n-1;i++){
				if(d[i]!=d[i+1]){
					if(d[i]<d[i+1]){
						if(b[i]!=0)ok=0;
					}
					else{
						if(b[i+1]!=0)ok=0;
					}
				}
			}
		}
		if(ok)cout<<"YES"<<'\n';
		if(!ok)cout<<"NO"<<'\n';
	}
}