#include<iostream>
#include<algorithm>
using namespace std;
int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}
int main(){
    int n;
    long long table[501];
    
    // Base case: G(1) = 0 (no pairs when n=1)
    table[1] = 0;
    
    // Recursive relation: G(n) = G(n-1) + sum of GCD(i, n) for i = 1 to n-1
    for(int i = 2; i <= 500; i++){
        table[i] = table[i-1]; // G(n-1)
        
        // Add sum of GCD(j, i) for j = 1 to i-1
        for(int j = 1; j < i; j++){
            table[i] += GCD(j, i);
        }
    }
    
    while(cin >> n && n){
        cout << table[n] << endl;
    }
    int gcd_res[]
}