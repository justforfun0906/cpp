#include<iostream>
#include"13520.hpp"
using namespace std;
int main(){
    Darray temp;
    temp.pushback(1);
    temp.pushback(2);
    cout<<temp.length()<<endl;
    temp[0]=10;
    cout<<temp[0];
    temp.clear();
    cout<<temp.length();
}