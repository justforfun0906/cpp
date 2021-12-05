#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(n;n>0;n--){
		int l;
		cin>>l;
		int a[l],b[l];
		for(int i=0;i<l;i++){
			cin>>a[i];
		}
		for(int i=0;i<l;i++){
			cin>>b[i];
		}
		sort(a,a+l);
		sort(b,b+l);
		long long sum=0,sum2=0;
		for(int i=0;i<l;i++){
			sum+=a[i]*b[i];
			sum2+=a[i]*b[l-i-1];
		}
		cout<<sum<<' '<<sum2<<endl;
	}
}
