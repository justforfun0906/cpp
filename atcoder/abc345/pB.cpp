#include<iostream>
using namespace std;
int main(){
    long long input; cin>>input;
    long long ans = input/10;
    long long rem = input%10;
    if(ans>=0 && rem!=0) ans++;
    if(input<0&&input>-10) ans = 0;
    cout<<ans;
}