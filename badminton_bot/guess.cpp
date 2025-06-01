#include<iostream>
using namespace std;
int main(){
    int ans = 100;
    int guess=0;
    while(guess!=ans){
        cout<<"please type another guess\n";
        cin>>guess;
        if(guess>ans){
            cout<<"guess smaller number.\n";
        }else if(guess<ans){
            cout<<"guess larger number.\n";
        }
    }
    cout<<"you guess it.";
}