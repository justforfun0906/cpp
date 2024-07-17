#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> find_borders(const string &s) {
    int n = s.size();
    vector<int> borders;

    // Check for each possible length of border
    for (int len = 1; len < n; ++len) {
        // Compare prefix and suffix of length `len`
        if (s.substr(0, len) == s.substr(n - len, len)) {
            borders.push_back(len);
        }
    }

    return borders;
}

int main() {
    string s;
    cin>>s;
    vector<int> borders = find_borders(s);
    for (int len : borders) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
