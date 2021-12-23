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
	int cnt=0;
	while(n!=0){
		cnt++;
		vi temp;
		int t=n;
		while(t){
			temp.push_back(t%10);
			t/=10;
		}
		n-=*max_element(temp.begin(),temp.end());
	}
	cout<<cnt;
}


