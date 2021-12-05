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
	while(cin>>n&&n!=0){
		vi num(100);
		int all=0,cnt=0;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				all++;
				if(__gcd(num[i],num[j])==1)
					cnt++;
			}
		}
		if(cnt){
			printf("%.6f\n", (float)sqrt((all * 6.0 / cnt)));
		}
		else{
			cout<<"No estimate for this data set."<<'\n';
		}		
	}
}


