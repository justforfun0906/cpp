#include<iostream>
using namespace std;
int main(){
    int a[4],b[4];
    int a_cnt=0, b_cnt=0;
    for(int i=0;i<4;i++)cin>>a[i];
    for(int i=0;i<4;i++)cin>>b[i];
    for(int i=0;i<4;i++){
        if(a[i]==b[i])a_cnt++;
        else{
            for(int j=0;j<4;j++){
                if(b[i]==a[j])b_cnt++;
            }
        }
    }
    cout<<a_cnt<<'A'<<b_cnt<<'B';
}