#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char a[7];
	int b[6];
	for(int i=0;i<7;i++)cin>>a[i];
	for(int i=0;i<6;i++){
		cout<<abs(a[i]-a[i+1]);
	}
}
