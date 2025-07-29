#include<iostream>
using namespace std;
int main(){
    int n,m,o;
    cin>>n>>m>>o;
    if(n-m > 0 && n-o > 0){
        cout<<n;
    }else if(m>o){
        cout<<m;
    }else{
        cout<<o;
    }
}