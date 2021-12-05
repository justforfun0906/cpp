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
		long long a;
		cin>>a;
		int cnt=0;
		while(a>=0){
			if(a>=10){
				a-=10;
				cnt+=25;
			}
			else if(a>=8){
				a-=8;
				cnt+=20;
			}
			else if(a>=6){
				a-=6;
				cnt+=15;
			}
		}
		cout<<cnt<<'\n';
	}
}

