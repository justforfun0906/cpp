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
	int time;
	cin>>time;
	for(int bruh=0;bruh<time;bruh++){
		int n,k;
		bool start=1;
		cin>>n>>k;
		string s;
		cin>>s;
		int cnt=0, ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')
				cnt++;
			if(s[i]=='1'){
				if(start){
					ans+=cnt/(k+1);
					start=0;
				}
				else{
					ans+=cnt/(k+1);
					if(cnt%(k+1)<k) ans--;
				}
				cnt=0;
			}
		}
		if(cnt) ans+=cnt/(k+1);
		if(cnt&&start) ans=((cnt-1)/(k+1))+1;
		cout<<ans<<'\n';
	}
}

