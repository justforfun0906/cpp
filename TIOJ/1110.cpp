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
	int n;
	cin>>n;
	for(int bruh=0;bruh<n;bruh++){
		int l;
		cin>>l;
		char a[l];
		vi cnt(26,0);
		for(int i=0;i<l;i++){
			cin>>a[i];
			cnt[a[i]-'a']++;
		}
		int maxnum=*max_element(cnt.begin(),cnt.end());
		for(int i=0;i<26;i++){
			if(cnt[i]==maxnum)cout<<char('a'+i);
		}
		cout<<'\n';
	}
}

