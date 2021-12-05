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
	auto cas=0;
	cin>>cas;
	for(int bruh=0;bruh<cas;bruh++){
		int n;
		cin>>n;
		int arr[n];
		double sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		int max=*max_element(arr,arr+n);
		sum-=max;
		double ans1=sum/(n-1);
		double ans2=max;
		ans2+=ans1;
		cout<<fixed<<setprecision(9)<<ans2<<'\n';
	}
}

