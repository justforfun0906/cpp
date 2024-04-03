#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
using namespace std;

class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string);
        String_Calculator& Add(const string x){
            s += x;
            return *this;
        }
        String_Calculator& Subtract(const string);
        String_Calculator& DividedBy(const string);
        void output(){
            cout << s << endl;
        }

    private:
        string s = "";
}; //end class String_Calculator
String_Calculator::String_Calculator(const string x){
    s = x;
}
String_Calculator& String_Calculator::Subtract(const string x){
    int i = 0;
    while(i < s.size() && i < x.size()){
        if(s[i] < x[i]){
            s[i] += 10;
            s[i+1]--;
        }
        s[i] -= x[i] - '0';
        i++;
    }
    while(i < s.size()){
        if(s[i] < '0'){
            s[i] += 10;
            s[i+1]--;
        }
        i++;
    }
    while(s.size() > 1 && s.back() == '0'){
        s.pop_back();
    }
    return *this;
}
String_Calculator& String_Calculator::DividedBy(const string x){
    string ans = "";
    int i = 0;
    while(i < s.size()){
        ans += s[i] / (x[0] - '0') + '0';
        s[i+1] += (s[i] % (x[0] - '0')) * 10;
        i++;
    }
    s = ans;
    while(s.size() > 1 && s.back() == '0'){
        s.pop_back();
    }
    return *this;
}
#endif // FUNCTION_H
