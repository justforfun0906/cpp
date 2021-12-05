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
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n;
	cin>>n;
	for(int bruh=0;bruh<n;bruh++){
		int len,lim;
		cin>>len>>lim;
		long long a[len],b[len];
		int cnt=1;
		for(int i=0;i<len;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(a,a+len,cmp);
		for(int i=0;i<len-1;i++){
			if(b[i+1]!=*upper_bound(a,a+len,b[i])){
				cnt++;
			}
		}
		if(cnt>lim) cout<<"No"<<'\n';
		else cout<<"Yes"<<'\n';
	}
}

