#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b=a;
    int cnt[a+1];
    for(int i=0;i<=a;i++){
        cnt[i] = 0;
    }
    for(int i=2;i<=a;i++){
        while(a%i==0){
            a/=i;
            cnt[i]++;
        }
    }
    int total = 0;
    for(int i=0;i<=b;i++){
        if(cnt[i]>0){
            total +=1;
        }
    }
    int now = 0;
    for(int i=2;i<=b;i++){
        if(cnt[i]>0){
            now=now+1;
            if(cnt[i]>1){
                cout<<i<<"^"<<cnt[i];
            }else{
                cout<<i;
            }
            if(now != total){
                cout<<'*';
            }
            //[0 2 0 0 1]->2
        }
    }
}