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
	int n;
	cin>>n;
	long long ans=0;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			ans+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<ans;
}

