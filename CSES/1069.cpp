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
	string a;
	cin>>a;
	int max=1,temp=1;
	for(int i=1;i<a.length();i++){
		if(a[i]==a[i-1]){
			temp++;
		}
		else temp=1;
		if(temp>max) max=temp;
	}
	cout<<max;
}

