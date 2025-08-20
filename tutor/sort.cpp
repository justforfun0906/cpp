#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    vector<int> v(5);
    v = {3 , 2 ,5 ,4 ,1 };
    sort(v.begin(), v.end(), cmp);
    for(auto x:v)cout<<x;
}