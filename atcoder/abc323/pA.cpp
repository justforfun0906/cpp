#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    int flag=1;
    for(int i=0;i<16;i++){
        if(i%2&&a[i]=='1')flag=0;
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
}