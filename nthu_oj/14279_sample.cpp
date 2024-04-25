#include <string>
#include <sstream>
#include <algorithm>
#include "14279.hpp"
#include <iostream>

Fraction Fraction::operator+(const Fraction& frac) {
    return Fraction(
        this->numerator * frac.denominator + this->denominator * frac.numerator,
        this->denominator * frac.denominator
    );
}

Fraction& Fraction::operator*=(const Fraction& frac) {
    Fraction new_frac = Fraction(this->numerator * frac.numerator, this->denominator * frac.denominator);
    this->numerator = new_frac.numerator;
    this->denominator = new_frac.denominator;
    return *this;
}

long long Fraction::getIntegerPart() {
    return this->numerator / this->denominator;
}

int Fraction::operator()(const int& digit) {
    long long n = this->numerator;
    for (int i = 0; i < digit; i++)
        n = (n * 10) % (this->denominator * 10);
    return (int)(n / this->denominator);
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << '/' << frac.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& frac) {
    std::string buffer;
    is >> buffer;
    if (is.eof())
        return is;
    frac.numerator = frac.parseNumerator(buffer);
    frac.denominator = frac.parseDenominator(buffer);
    return is;
}

FractionList::FractionList(const FractionList& frac) {
    // deep copy current node data
    this->fraction = new Fraction(*frac.fraction);
    // do with next one and connect to current node
    this->nextFraction = frac.nextFraction == nullptr
        ? nullptr
        : new FractionList(*frac.nextFraction);
}

FractionList::~FractionList() {
    // delete current node data
    if (this->fraction != nullptr)
        delete this->fraction;
    // delete next one
    if (this->nextFraction != nullptr)
        delete this->nextFraction;
}

FractionList& FractionList::operator=(const FractionList& frac) {
    // here use `new_frac`'s constructor to deeep copy old data
    FractionList new_frac = FractionList(frac);
    Fraction* temp_frac = new_frac.fraction;
    FractionList* temp_next = new_frac.nextFraction;
    new_frac.fraction = this->fraction;
    new_frac.nextFraction = this->nextFraction;
    this->fraction = temp_frac;
    this->nextFraction = temp_next;
    // here use `new_frac`'s destructor to delete old data
    return *this;
}

FractionList* FractionList::operation(string ope, Fraction* frac) {
    if (ope == "*") {
        *this->fraction *= *frac;
        return this;
    } else {
        FractionList* new_frac_node = new FractionList(frac);
        this->nextFraction = new_frac_node;
        return new_frac_node;
    }
}

Fraction FractionList::getResult() {
    Fraction summing = Fraction();
    for (FractionList* frac_node = this; frac_node != nullptr; frac_node = frac_node->nextFraction)
        summing = summing + *frac_node->fraction;
    return summing;
}