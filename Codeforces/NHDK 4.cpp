//code for fun
#include<iostream>
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
long long n,k;
int main(){
	cin>>n>>k;
	cout<<"ok1";
	long long a[n];
	long long b[n][4];
	vector <long long> q(2*n);
	for(int i=0;i<n;i++){
		cout<<"ok"<<'\n';
		cin>>b[i][0]>>b[i][1]>>b[i][2]>>b[i][3];
		a[i]=b[i][0]+b[i][1]+b[i][2]+b[i][3]-k;
		q[i*2]=b[i][0]+b[i][1];
		q[i*2+1]=b[i][2]+b[i][3];
	}
	int ansloc1=min_element(a,a+n)-&a[0];
	long long ans1=*min_element(a,a+n);
	int ansloc2=min_element(q.begin(),q.end())-q.begin();
	long long ans2=*min_element(q.begin(),q.end());
	*min_element(q.begin(),q.end())=1e9;
	int ansloc3=min_element(q.begin(),q.end())-q.begin();
	long long ans3=*min_element(q.begin(),q.end());
	
	
	if(ans1<ans2+ans3) cout<<ansloc1+1<<' '<<1<<' '<<ansloc1+1<<' '<<2;
	else cout<<(ansloc2/2)+1<<' '<<(ansloc2%2)+1<<' '<<(ansloc3/2)+1<<' '<<(ansloc3%2)+1;
}
