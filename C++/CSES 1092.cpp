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
	vector <int> a,b;
	if(n%4!=0&&n%4!=3) cout<<"NO";
	else if(n%4==0){
		for(int i=1;i<=n/2;i++){
			if(i%2==1){
				a.push_back(i);
				a.push_back(n-i+1);
			}
			else{
				b.push_back(i);
				b.push_back(n-i+1);
			}
		}
		cout<<"YES"<<"\n";
		cout<<n/2<<'\n';
		for(auto i:a)cout<<i<<' ';
		cout<<'\n'<<n/2<<'\n';
		for(auto i:b)cout<<i<<' ';
	}
	else{
		b.push_back(n);
		a.push_back(1);
		a.push_back(n-1); 
		for(int i=2;i<(n+1)/2;i++){
			if(i%2==1){
				a.push_back(i);
				a.push_back(n-i);
			}
			else{
				b.push_back(i);
				b.push_back(n-i);
			}
		}
		cout<<"YES"<<"\n";
		cout<<n/2+1<<'\n';
		for(auto i:a)cout<<i<<' ';
		cout<<'\n'<<n/2<<'\n';
		for(auto i:b)cout<<i<<' ';
	}
}

