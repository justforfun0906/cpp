//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
ll ans;
void merge_sort(int a[], int l, int r) { //[l, r)
	if (r - l <= 1) return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid, r); //thus, [l, mid) and [mid, r) are sorted
	int sorted[r - l];
	int ri = mid, ind = 0;
	long long m=0;
	for (int li = l;li < mid;li++) { //two pointers
		ans+=m;
		while (ri < r && a[ri] < a[li]) {//a[l]~a[mid],a[mid+1]~a[r]³æ½Õ 
			sorted[ind] = a[ri];
			ind++; ri++;
			m++;ans++;
		}
		sorted[ind] = a[li];
		ind++;
	}
	while (ri < r) { //insert remaining elements
		sorted[ind] = a[ri];
		ind++, ri++;
	}
	for (int i = 0;i < r - l;i++) a[i + l] = sorted[i];
}
int main(){
	faster;
	int n,cas=1;
	while(cin>>n&&n!=0){
		ans = 0;
		int k = n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		merge_sort(a,0,n);
		cout<<"Case #"<<cas<<": "<<ans<<'\n';
		cas++;
	}
}

