#include<bits/stdc++.h>
using namespace std;
 
const int N = 110;
const int MxLen = 5010;
const long long mod = 1000000007, M = 37;
 
int n, q;
long long pw[5010];
long long hash_table[N], len[N];
 
void solve(){
    pw[0] = 1;
    for(int i = 1; i < MxLen; i++)
        pw[i] = pw[i - 1] * M % mod;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        len[i] = s.size();
        for(int j = 0; j < len[i]; j++)
            hash_table[i] = (hash_table[i] + s[j] * pw[j] % mod) % mod; 
    }
    while(q--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        x--, y--;
        if(c == 'E')
            cout << (hash_table[x] == hash_table[y] ? "Y" : "N") << '\n';
        else{
            hash_table[x] = (hash_table[x] + hash_table[y] * pw[len[x]] % mod) % mod;
            len[x] += len[y];
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
 