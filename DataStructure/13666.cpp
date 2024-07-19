#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    size_t pos;
    // Repeat until "ABC" is not found
    while ((pos = S.find("ABC")) != string::npos) {
        S.erase(pos, 3); // Remove "ABC" from the string
    }

    cout << S << endl; // Print the final result
    return 0;
}