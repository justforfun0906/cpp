#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	int n;
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	int m;
	cin>>m;
	if(n>m){
        cout << "Impossible";
        return 0;
    }
	vector < pair<int,int> > b(m+5); 
	for(int i=0;i<m;i++){
		cin>>b[i].first>>b[i].second;//first=nutrition, second=price
	}
	sort(b.begin(),b.end(),cmp);
	long long cnt=0;
	int in=0;
	for(int i=0;i<m;i++){
		if(b[i].first>=p[in]){
			cnt+=b[i].second;
			in++;
			if(in>=n)break;
		}
	}
	if(in<n) cout<<"Impossible";
	else cout<<cnt;
}
