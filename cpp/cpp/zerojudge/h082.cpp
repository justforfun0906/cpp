#include<bits/stdc++.h>
using namespace std;
int s[1005];
int t[1005];
int lose_cnt[1005];
vector <int> num, winner, loser;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int index;
		cin>>index;
		num.push_back(index);
	}
	//input end
	while(num.size()>1){	//the final winner isn't out yet
		for(int i=0;i<=(int)num.size()-2;i+=2){
			long long x=num[i],y=num[i+1];
			long long a=s[x],b=t[x],c=s[y],d=t[y];
			if(a*b>=c*d){
				lose_cnt[y]++;
				s[x]=a+	c*d/(2*b);
				t[x]=b+ c*d/(2*a);
				s[y]=c+	c/2;
				t[y]=d+	d/2;
				winner.push_back(x);
				if(lose_cnt[y]<m)loser.push_back(y);
			}
			else{
				lose_cnt[x]++;
				s[x]=a+	a/2;
				t[x]=b+	b/2;
				s[y]=c+	a*b/(2*d);
				t[y]=d+	a*b/(2*c);
				winner.push_back(y);
				if(lose_cnt[x]<m)loser.push_back(x);
			}
		}
		if((int)num.size()%2==1){
			winner.push_back(num.back());
		}
		num=winner;
		for (int i:loser) num.push_back(i);
		winner.clear();
		loser.clear();
	}
	cout<<num[0]<<'\n';
}