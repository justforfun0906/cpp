#include<iostream>
using namespace std;
int f(int x){
    return 3*x;
}
void g(int x){
    cout<<"now x = "<<x<<endl;
    if(x>0){
        g(x-1);
    }
}
void S(int &x, int &y){
    //pass by reference
}
int main(){
    int a, b;
    cin>>a>>b;
    // int temp = b;
    // b = a;
    // a = temp;
    S(a,b);
}