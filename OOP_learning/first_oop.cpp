#include<iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base Class Constructor called" << endl;
    }
    virtual void test(){
        cout << "Base Class Test Function" << endl;
    }
};
class X: virtual public Base{
public:
    X(){
        cout << "Derived Class X Constructor"<< endl;
    }
    void test() override{
        cout << "Derived Class X Test Function" << endl;
    }
};
class Y: virtual public Base{
public:
    Y(){
        cout << "Derived Class Y Constructor"<< endl;
    }
    void test() override{
        cout << "Derived Class Y Test Function" << endl;
    }
};
class XY: public X, public Y{
public:
    XY(){
        cout << "Derived Class XY Constructor"<< endl;
    }
    void test() override{
        cout << "Derived Class XY Test Function" << endl;
    }
};
int main(){
    XY obj;
    Base *ind = &obj;
    ind->test();
    obj.test();
    obj.X::test();
    obj.Y::test();
    obj.Base::test();
    return 0;
}
