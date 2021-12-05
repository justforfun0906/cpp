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
	int a,b;
	while(cin>>a>>b){
		if(a<b)
			swap(a,b);
		if(a%b==0){
			cout<<"Y"<<'\n';
		}
		else{
			cout<<"N"<<'\n';
		}
	}

}

