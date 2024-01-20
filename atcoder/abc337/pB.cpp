#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    bool flag  = true;
    for(int i=1;i<n&&flag;i++){
        if(s[i]<s[i-1]) flag = false;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}