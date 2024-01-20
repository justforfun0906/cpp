#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a_cnt =0, b_cnt =0;
    while(n--){
        int a,b;
        cin>>a>>b;
        a_cnt+=a;
        b_cnt+=b;
    }
    if(a_cnt>b_cnt) cout<<"Takahashi"<<endl;
    else if(b_cnt>a_cnt)cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
}