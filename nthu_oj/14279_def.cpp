#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <numeric>
#include "14279.hpp"
using namespace std;
Fraction Fraction::operator+(const Fraction &f){
    long long num = this->numerator * f.denominator + f.numerator * this->denominator;
    long long den = this->denominator * f.denominator;
    return Fraction(num,den);
}
Fraction& Fraction::operator*=(const Fraction &f){
    this->numerator *= f.numerator;
    this->denominator *= f.denominator;
    return *this;
}
int Fraction::operator()(const int& n){//return the nth digit after the decimal point
    long long num = this->numerator;
    long long den = this->denominator;
    for(int i=0;i<n;i++){
        num = num*10;
    }
    return (num/den)%10;
}
long long Fraction::getIntegerPart(){
    return this->numerator/this->denominator;
}
ostream& operator<<(ostream &os,const Fraction &f){
    os<<f.numerator<<"/"<<f.denominator;
    return os;
}
istream& operator>>(istream &is,Fraction &f){
    string frac;
    is>>frac;
    f.numerator = f.parseNumerator(frac);
    f.denominator = f.parseDenominator(frac);
    return is;
}

FractionList::FractionList(const FractionList &f){
    FractionList *temp = this;
    this->fraction = new Fraction(*(f.fraction));
    while(f.nextFraction!=NULL){
        this->fraction = new Fraction(*(f.nextFraction->fraction));
        temp->nextFraction = new FractionList(*(f.nextFraction->fraction));
        temp = temp->nextFraction;
    }
}
int main(){
    Fraction a(1,2), b(1,3);
    cout << a + b << endl;
    a*=b;
    cout << a << endl;
}