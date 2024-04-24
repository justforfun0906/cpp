#include <iostream>
#include <string>
#include <algorithm>
#include "14279.hpp"
using namespace std;

int main() {
    Fraction fraction;
    while (cin >> fraction) {

        FractionList *toMultiply = new FractionList(new Fraction(fraction));
        FractionList *lastFraction = toMultiply;
        cout<<"check"<<endl;
        string ope;
        while (cin >> ope) {
            cout<<"operator ="<<ope<<endl;
            if (ope == "=") break;
            cin >> fraction;
            lastFraction = lastFraction->operation(ope, new Fraction(fraction));
            lastFraction->printList();
        }//pass
        cin >> ope;//'?'
        cout<<"check"<<endl;
        FractionList *multiplied = new FractionList(*toMultiply), toAdd;
        cout<<"check"<<endl;//pass
        //didn't get into getResult
        //FractionList operator= is not working
        Fraction answer = (toAdd = *multiplied).getResult();
        delete toMultiply, multiplied;
        
        cout << answer << " ";
        cout << answer.getIntegerPart() << ".";
        for (int i = 1; i <= 20; ++i) cout << answer(i);
        cout << endl;

    }
}