#include<iostream>
using namespace std;
int main(){
    int m; cin>>m;
    int day=0;
    int month[m];
    for(int i=0;i<m;i++){
        int temp; cin>>temp;
        month[i]=temp;
        day+=temp;
    }
    day++;
    day=day/2;
    int ans_m=1;
    for(int i=0;i<m;i++){
        if(day>month[i]){
            ans_m++;
            day-=month[i];
        }
        else{
            cout<<i+1<<' ';
            break;
        }
    }
    cout<<day;
}