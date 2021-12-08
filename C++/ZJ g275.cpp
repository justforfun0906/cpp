//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	faster;
	int n;
	cin>>n;
	while(n--){
		int a[7],b[7];
		for(int i=0;i<7;i++){
			cin>>a[i];
		}
		for(int i=0;i<7;i++){
			cin>>b[i];
		}
		bool flag=1;
		if(a[1]==a[3]||b[1]==b[3]){
			cout<<'A';
			flag=0;
		}
		else if(a[1]!=a[5]||b[1]!=b[5]){
			cout<<'A';
			flag=0;
		}
		if(a[6]!=1||b[6]!=0){
			cout<<'B';
			flag=0; 
		}
		if(a[1]==b[1]){
			cout<<'C';
			flag=0; 
		}
		else if(a[3]==b[3]){
			cout<<'C';
			flag=0;
		}
		else if(a[5]==b[5]){
			cout<<'C';
			flag=0;
		}
		if(flag) cout<<"None";
		cout<<'\n';
	} 
}

