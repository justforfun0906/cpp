#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector< vector<pair <int, int > > > g(15);
int check(int a,int b){
    for(int i=0;i<g[a].size();i++){
        if(g[a][i].first == b) {
            return g[a][i].second;
        }
    }
    return 0;
}
int ans = 0;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++){
        v.push_back(i+1);
    }
    for (int i = 0; i < m ; i++){
        int a, b, d; cin>>a>>b>>d;
        g[a].push_back(make_pair(b,d));
        g[b].push_back(make_pair(a,d));
    }
    int temp=0;
    for(int i=0;i<n-1;i++){
        int a = v[i];
        int b = v[i+1];
        //cout<<a<<b<<' ';
        if(check(a,b)>0){
            temp += check(a,b);

        }else{
            break;
        }
    }
    ans = max(temp, ans);
    while (next_permutation(v.begin(), v.end())){
        temp=0;
        for(int i=0;i<n-1;i++){
            int a = v[i];
            int b = v[i+1];
            //cout<<a<<b<<' ';
            if(check(a,b)){
                temp += check(a,b);
            }else{
                break;
            }
        }
        ans = max(ans, temp);
    }
    cout<<ans;
    return 0;
}