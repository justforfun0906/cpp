#include <cmath>
#include <iostream>
template <typename T, class Func>
void ForEach(T _begin, T _end, Func _func) {
    for (; _begin != _end; _begin++) {
        _func(*_begin);
} }
struct Power {
    int exp;
    void operator()(int &base) {
        exp = 2;
        base = std::pow(base, exp);
} 
};
int main() {
    int A[] = { 1, 2, 3, 4, 5 };
    ForEach(A, A + 5, Power());
    for(int i=0;i<5;i++) std::cout<<A[i]<<' ';
    return 0;
}