#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> find_pi(string &s){
    int n = s.size();
    vector<int> pi(n, 0);
    int k = 0;
    for(int i=1;i<n;i++){
        while(k>0&&s[i]!=s[k]){
            k = pi[k-1];
        }
        if(s[i] == s[k]){
            k++;
        }
        pi[i] = k;
    }
    return pi;
}
vector<int> find_borders(string &s) {
    int n = s.size();
    vector<int> borders;
    vector pi = find_pi(s);
    int k = pi.back();
    while(k > 0){
        borders.push_back(k);
        k = pi[k-1];
    }
    //sort(borders.begin(), borders.end());

    return borders;
}

int main() {
    string s;
    cin>>s;
    vector<int> borders = find_borders(s);
    sort(borders.begin(), borders.end());
    for (int len : borders) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
