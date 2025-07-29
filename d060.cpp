#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>25){
        cout<<60-(n-25);
    }else{
        cout<<25-n;
    }
}