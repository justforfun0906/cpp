#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt[10];
    set<int> sseett;
    memset(cnt,0,sizeof(cnt));
    int a,b,c;
    cin>>a>>b>>c;
    sseett.insert(a);
    sseett.insert(b);
    sseett.insert(c);
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    cout<<*max_element(cnt, cnt+10)<<' ';
    for(auto i=sseett.rbegin();i!=sseett.rend();i++){
        cout<<*i<<' ';
    }
}
