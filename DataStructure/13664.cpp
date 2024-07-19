#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> find_pi(string &s){
    vector<int> pi(n);
    pi[0] = 0;
    int k = 0;
    for(int i=1;i<n;i++){
        while(k>0 && s[k]!=s[i]) k = pi[k-1];
        if(s[k]==s[i]) k++;
        pi[i] = k;
    }
    return pi;
}
vector<int> find_borders(string &s){
    vector<int> pi = find_pi(s);
    vector<int> borders;
    int k = pi.back();
    while(k>0){
        borders.push_back(k);
        k = pi[k-1];
    }
    return borders;
}
int main(){
    string s;
    cin>>s;
    n = s.size();
    vector<int> borders = find_borders(s);
    sort(borders.begin(),borders.end());
    for(int i:borders) cout<<i<<' ';
    cout<<'\n';
}