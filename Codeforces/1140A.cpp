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
	int pages;
	cin>>pages;
	int day_cnt=0;
	int max=0;
	for(int i=1;i<=pages;i++){
		int temp;
		cin>>temp;
		if(temp>max) max=temp;
		if(i==max) day_cnt++;
	}
	cout<<day_cnt;
}

