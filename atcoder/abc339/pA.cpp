#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int last_dot = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '.'){
            last_dot = i;
        }
    }
    for(int i=last_dot+1;i<s.size();i++){
        cout << s[i];
    }
}