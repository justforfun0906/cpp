#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string S;
    cin >> S;

    stringstream ss;
    size_t pos = 0, prev = 0;
    // Find each occurrence of "ABC" and append the parts of S without "ABC" to ss
    while ((pos = S.find("ABC", prev)) != string::npos) {
        ss << S.substr(prev, pos - prev); // Append part of S before "ABC"
        prev = pos + 3; // Move past the "ABC"
    }
    ss << S.substr(prev); // Append the remainder of S

    cout << ss.str() << endl; // Print the final result
    return 0;
}