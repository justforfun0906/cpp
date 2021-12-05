#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
const int N = 2 * 1e5;
int a[N];
long long st[4*N];
int tag[4*N];
void upd(int l, int r, int ind, int val){
	st[ind]+=(r-l)*val;
	tag[ind]+=val;
}
void push(int l,int r,int ind){
	int mid=(l+r)/2;
	upd(l,mid,ind*2,tag[ind]);
	upd(mid+1,r,ind*2+1,tag[ind]);
	tag[ind]=0;//pushed
}
void pull(int ind){
	st[ind]=st[ind*2]+st[ind*2+1];
}
void mod(int l,int r,int ql, int qr, int ind, int val){
	if(qr<l||ql>r) return;//沒交集 
	if(qr>=r&&ql<=l){//[ql,qr]包含[l,r]; 
		upd(l,r,ind,val);
		return;
	}
	int mid=(l+r)/2;
	push(l,r,ind);//不是很懂為啥是[l,r]不是[ql,qr]?
	mod(l,mid,ql,qr,ind*2,val);
	mod(mid+1,r,ql,qr,ind*2+1,val);
	pull(ind);
}
int query(int l,int r,int ind,int ql,int qr){
	if(ql>=r||qr<=l) return 0;
	if(ql<=l&&qr>=r) return st[ind];
	int mid=(l+r)/2;
	push(l,r,ind);
	return query(l,mid,ind*2,ql,qr)+query(mid,r,ind*2+1,ql,qr);
}
void build(int l,int r, int ind){
	if(l==r){
		st[ind]=a[l];
	}
	else{
		int mid=(l+r)/2;
		build(l,mid, ind*2);
		build(mid+1,r, ind*2+1);
		pull(ind);
	}
}
int main(){
	faster;
	int l,q;
	cin>>l>>q;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	build(1,l,1);
	while(q--){
		int dem;
		cin>>dem;
		if(dem==1){
			int ql,qr,val;
			cin>>ql>>qr>>val;
			mod(1,l,ql,qr,1,val);
		}
		else{
			int q;
			cin>>q;
			cout<<query(1,l,1,q,q)<<'\n';
		}
		for(int i=1;i<=4*l;i++){
			cout<<st[i]<<' ';
		}
		cout<<'\n';
	}
}

