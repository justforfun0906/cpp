#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to compute the prefix function (also known as KMP table)
std::vector<int> computePrefixFunction(const std::string &s) {
    int n = s.length();
    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

// Function to find all border lengths of a given string
std::vector<int> findAllBorderLengths(const std::string &s) {
    std::vector<int> pi = computePrefixFunction(s);
    std::vector<int> borders;
    int k = pi.back();
    while (k > 0) {
        borders.push_back(k);
        k = pi[k - 1];
    }
    return borders;
}

int main() {
    std::string s;
    //std::cout << "Enter a string: ";
    std::cin >> s;

    std::vector<int> borders = findAllBorderLengths(s);

    //std::cout << "Border lengths: ";
    sort(borders.begin(), borders.end());
    for (int len : borders) {
        std::cout << len << " ";
    }
    std::cout << std::endl;

    return 0;
}