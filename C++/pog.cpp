//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int g(int a){
	if(a<=2)
		return a*a-1;
	else
		return 2;
}

int h(int a){
	if(a<2)
		return -1;
	else
		return 2+h(a-1)-h(a-2);
}

int f(int a){
	int tmp=h(a);
	if(a>tmp){
		return f(a-1)-tmp;
	}
	else if(a<tmp){
		int tmp2=g(a);
		return f(tmp2)-tmp2;
	}
	else{
		return 1;
	}
}

int main(){
	faster;
	int n;
	cin >> n;
	cout << f(n); 
}

