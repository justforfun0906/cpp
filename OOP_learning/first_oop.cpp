#include<iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base Class Constructor called" << endl;
    }
};
class X: public Base{
public:
    X(){
        cout << "Derived Class X Constructor"<< endl;
    }
};
class Y: public Base{
public:
    Y(){
        cout << "Derived Class Y Constructor"<< endl;
    }
};
class XY: public X, public Y{
public:
    XY(){
        cout << "Derived Class XY Constructor"<< endl;
    }
};
int main(){
    XY obj;
    return 0;
}
