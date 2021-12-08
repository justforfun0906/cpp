//code for fun
#include<iostream>
#include<stdio.h>
#include<utility>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
	faster;
	long long temp[63];
	string compare[63];
	temp[0]=1;
	compare[0]=to_string(temp[0]);
	for(int i=1;i<63;i++){
		temp[i]=temp[i-1]*2;
		compare[i]=to_string(temp[i]);
	}
	int n;
	cin>>n;
	for(int bruh=0;bruh<n;bruh++){
		unsigned long long ans=1e10;
		string a;
		cin>>a;
		for(int i=0;i<63;i++){
			int index=0;
			int same=0;
			for(int j=0;j<a.size();j++){
				if(compare[i][index]==a[j]){
					index++;
					same++;
				}
			}
			ans=min(ans,(unsigned long long)((a.size()-same)+(compare[i].size()-same)));
		}
		cout<<ans<<'\n';
	}
}

