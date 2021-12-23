//code for fun
#include<iostream>
#include<utility>
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
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i){
		long long f,s,time;
		cin>>f>>s>>time;
		ll sum=0;
		if(time%2){
			sum+=(ll)f*((time/2)+1);
			sum-=(ll)s*(time/2);
		}
		else{
			sum+=(ll)f*(time/2);
			sum-=(ll)s*(time/2);
		}
		cout<<sum<<'\n';
	}
}
