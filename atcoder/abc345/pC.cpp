#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> cnt(30,0);
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(cnt[s[i]-'a']==0){
            ans++;
        }
        cnt[s[i]-'a']++;
    }
    cout<<ans;
}