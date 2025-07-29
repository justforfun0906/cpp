#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a[5];
        for(int i = 0 ;i<4;i++){
            cin>>a[i];
        }
        if(a[3]-a[2] == a[2]-a[1]){
            a[4] = a[3]-a[2] + a[3];
        }else{
            a[4] = a[3]/a[2] * a[3];
        }
        for(int i=0;i<5;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
}