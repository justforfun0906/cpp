//code for fun
#include<stdio.h>
#include<vector>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int arr[100005];
int st[400005];
void build(int L,int R,int Q,int index){
	//
}
bool read(int &x){
    x = 0;
    int w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
        if(ch == '-') w = -1;
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    x *= w;
    return true;
}

inline void outputll(ll x) {
    static signed sta[20];
    if(x < 0) putchar('-'), x = -x;
    signed top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);
}
inline void output(int x) {
    static signed sta[20];
    if(x < 0) putchar('-'), x = -x;
    signed top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);
}
signed main(){
	//faster;
	int n, t = 1;
	while(read(n)){
		if(n == 0) break;
		ll ans = 0;
		vector<int> st;
		for(int i = 1, x; i <= n; ++i){
			read(x);
			auto it = lower_bound(st.begin(), st.end(), x);
			int k = it - st.begin();
			st.insert(it, x);
			ans += ((int) st.size() - k);
		}
		putchar('C'),putchar('a'),putchar('s'),putchar('e'),putchar(' '),putchar('#');
		output(t);
		putchar(':'),outputll(ans - n),putchar('\n');
		++t;
	}
}

