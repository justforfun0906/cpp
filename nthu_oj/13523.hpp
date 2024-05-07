#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>
class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void popback(void);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};
Darray::~Darray(){
    delete[] data;
}
int& Darray::operator[](int index){
    return data[index];
}
void Darray::pushback(int x){
    if(size == capacity){
        resize();
    }
    data[size++] = x;
}
void Darray::popback(void){
    if(size > 0) size--;
}
void Darray::clear(void){
    size = 0;
}
int Darray::length(void){
    return size;
}
void Darray::resize(void){
    int *tmp = new int[capacity*2];
    for(int i=0; i<size; i++){
        tmp[i] = data[i];
    }
    delete[] data;
    data = tmp;
    capacity *= 2;
}
class INT {
    public:
        void operator+=(INT&);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT &);
    private:
        Darray data;
};
void INT::operator+=(INT &x){
    int range = this->data.length()<x.data.length()?this->data.length():x.data.length();
    int carry = 0;
    for(int i=0;i<range;i++){
        this->data[i] += x.data[i]+carry;
        if(this->data[i]>=10){
            this->data[i] -= 10;
            carry = 1;
        }else{
            carry = 0;
        }
    }
    if(carry){
        if(this->data.length()<x.data.length()){
            this->data.pushback(x.data[range]+carry);
        }else{
            this->data[range] += carry;
        }
    }
}
std::istream &operator>>(std::istream &is, INT &x){
    std::string str;
    is >> str;
    for(int i=str.length()-1;i>=0;i--){
        x.data.pushback(str[i]-'0');
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, INT &x){
    for(int i=x.data.length()-1;i>=0;i--){
        os << x.data[i];
    }
    return os;
}
#endif
