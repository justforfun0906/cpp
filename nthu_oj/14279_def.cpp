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
    //TODO: check how this works lol
    long long num = this->numerator;
    long long den = this->denominator;
    for(int i=0;i<n;i++){
        num = num*10%(this->denominator*10);
    }
    return (int)(num/this->denominator);
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
    if(is.eof()) return is;//if the input is empty
    f.numerator = f.parseNumerator(frac);
    f.denominator = f.parseDenominator(frac);
    return is;
}
//TODO: read this func
FractionList::FractionList(const FractionList &f){//deep copy
    this->fraction = new Fraction(*(f.fraction));
    this->nextFraction = f.nextFraction==NULL
    ? nullptr
    : new FractionList(*(f.nextFraction));//recursively copy the next one until nullptr
}
//TODO: wtf does this do
FractionList& FractionList::operator=(const FractionList& f){
    FractionList new_fraclist(f);
    swap(this->fraction,new_fraclist.fraction);
    swap(this->nextFraction,new_fraclist.nextFraction);
    return *this;
}
FractionList::~FractionList(){
    //delete current node data
    if(this->fraction!=NULL) delete this->fraction;
    //delete next one
    if(this->nextFraction!=NULL) delete this->nextFraction;
}
FractionList* FractionList::operation(string ope, Fraction *frac){
    if(ope=="+"){
        this->nextFraction = new FractionList(frac);
        return this->nextFraction;
    }else if(ope=="*"){
        *(this->fraction) *= *frac;
        return this;
    }
}
Fraction FractionList::getResult(){
    FractionList *temp = this;
    Fraction result = *(temp->fraction);
    while(temp->nextFraction!=nullptr){
        temp = temp->nextFraction;
        result = result + *(temp->fraction);
    }
    return result;
}