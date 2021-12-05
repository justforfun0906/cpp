#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
const int N = 2 * 1e5;
long long a[N];
long long st[4*N];
long long tag[4*N];
void upd(int l, int r, int ind, long long val){
	st[ind]+=(r-l+1)*val;
	tag[ind]+=val;
}
void push(int l,int r,long long ind){
	int mid=(l+r)/2;
	upd(l,mid,ind*2,tag[ind]);
	upd(mid+1,r,ind*2+1,tag[ind]);
	tag[ind]=0;//pushed
}
void pull(int ind){
	st[ind]=st[ind*2]+st[ind*2+1];
}
void mod(int l,int r,int ql, int qr, int ind, long long val){
	if(qr>=r&&ql<=l){//[ql,qr]¥]§t[l,r]; 
		upd(l,r,ind,val);
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) mod(l,mid,ql, qr, ind*2, val);
	else if(ql>mid) mod(mid+1,r,ql,qr, ind*2+1,val);
	else{
		mod(l,mid,ql, qr, ind*2, val);
		mod(mid+1,r,ql,qr, ind*2+1,val);
	}
	pull(ind);
}
long long query(int l,int r,int ind,int ql,int qr){
	if(ql>r||qr<l) return 0;
	if(ql==l&&qr==r) return st[ind];
	int mid=(l+r)/2;
	push(l,r,ind);
	if(qr<=mid) return query(l, mid, ind*2, ql, qr);
	else if(mid<ql) return query(mid+1,r,ind*2+1,ql,qr);
	else{
		return query(l, mid, ind*2, ql, mid)+query(mid+1,r,ind*2+1,mid+1,qr);
	}
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
	}
}

