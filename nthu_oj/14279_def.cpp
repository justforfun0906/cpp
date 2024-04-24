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

FractionList::FractionList(const FractionList &f){//deep copy
    FractionList *temp = this;
    const FractionList *f_temp = &f;
    while(f_temp->nextFraction!=NULL){//until the last fractionList node
        temp->fraction = new Fraction(*(f_temp->nextFraction->fraction));
        temp->nextFraction = new FractionList(f.nextFraction->fraction);//create a new FractionList node with the other constructor
        temp = temp->nextFraction;
        f_temp = f_temp->nextFraction;//move to next node
    }
    temp->fraction = new Fraction(*(f.fraction));
    temp->nextFraction = NULL;//the last node
}
FractionList& FractionList::operator=(const FractionList& f){
    *(this->fraction) = Fraction(*(f.fraction));
    return *this;
}
FractionList::~FractionList(){
    FractionList *temp = this;
    while(temp->nextFraction!=NULL){
        FractionList *temp2 = temp;
        temp = temp->nextFraction;
        delete temp2->fraction;
        delete temp2;
    }
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
    while(temp->nextFraction!=NULL){
        temp = temp->nextFraction;
        result = result + *(temp->fraction);
    }
    return result;
}