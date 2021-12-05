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
long long pos[105],dis[105];
using namespace std;
int main(){
	int bridge,river,wood;
	cin>>bridge>>river>>wood;
	for(int i=1;i<=wood;i++){
		cin>>pos[i];
		dis[i]=pos[i]-pos[i-1];
		if(dis[i]>bridge||pos[i]>river){
			cout<<"impossible";
			break;
		}
	}
}

