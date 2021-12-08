//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
long long ans=0;
void merge_sort(int a[], int l, int r) { //[l, r)
	if (r - l <= 1) return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid, r); //thus, [l, mid) and [mid, r) are sorted
	int sorted[r - l];
	int li = l, ind = 0;
	for (int ri = mid;ri < r;ri++) { //two pointers
		while (li < mid && a[li] <= a[ri]) {
			sorted[ind] = a[li];
			ind++, li++;
		}
		sorted[ind] = a[ri];
		ind++;
	}
	while (li < mid) { //insert remaining elements
		sorted[ind] = a[li];
		ind++, li++;
		ans++;
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
		ans=0;
	}
}

