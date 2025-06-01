#include<iostream>
using namespace std;
int main(){
    char b;
    cin>>b;
    if(b=='+'){
        int a, c;
        cin>>a>>c;
        cout<<a+c;
    }else if(b=='-'){
        int a,c;
        cin>>a>>c;
        cout<<a-c;
    }else if(b=='*'){
        int a, c;
        cin>>a>>c;
        cout<<a*c;
    }else if(b=='/'){
        int a,c;
        cin>>a>>c;
        cout<<a/c<<"..."<<a%c;
        //a = 5, c = 2 -> 2...1
    }
}