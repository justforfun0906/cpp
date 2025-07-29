#include<iostream>
using namespace std;
int main(){
    int N, M;//base;
    cin>>N>>M;
    while(M != 0){
        if(M%N == 0){
            cout<<M/N<<'\n';
        }else{
            cout<<N - M%N<<'\n';
        }
        cin>>M;
    }
}