#include<bits/stdc++.h>
using namespace std;
int enemy[10005];
int solve(int atk,int e_num){
    for(int i=0;i<e_num;i++){
        if(atk>enemy[i])atk+=enemy[i];
        else{
            return atk;
        }
    }
    return atk;
}
int main(){
    int num, ori;
    cin>>num>>ori;
    for(int i=0;i<num;i++)cin>>enemy[i];
    cout<<solve(ori,num);
}