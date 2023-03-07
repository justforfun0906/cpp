#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		vector<int> a(105,0);
		while(n--){
			int temp;
			cin>>temp;
			a[temp]++;
		}
		int cnt=0;
		for(int i=1;i<=100;i++){
			if(a[i]>c)cnt+=c;
			else cnt+=a[i];
		}
		cout<<cnt<<'\n';
	}
}

