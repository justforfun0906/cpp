#include "function.h"
#include <iostream>
using namespace std;
String_Calculator& String_Calculator::Add(string x){
    s += x;
    return *this;
}
void String_Calculator::output() const{
    cout << s << endl;
}
String_Calculator::String_Calculator(const string x){
    s = x;
}
String_Calculator& String_Calculator::Subtract(const string x){
    int idx = s.find(x);
    if(idx == string::npos){
        s = "error";
    }else{
        s.erase(idx, x.size());
    }
    return *this;
}
String_Calculator& String_Calculator::DividedBy(const string x){
    int idx = s.find(x);
    int cnt = 0;
    while(idx != string::npos){
        cnt++;
        idx = s.find(x, idx + 1);
    }
    s = to_string(cnt);
    return *this;
}