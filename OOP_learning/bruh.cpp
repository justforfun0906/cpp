#include <algorithm>
#include <iostream>
using namespace std;
template<typename Iter, typename Func>
void Sort(Iter first, Iter last, Func Comp) {
    while (first++ != last) {
        Iter cur = first;
        while (++cur != last) {
            if (Comp(*first, *cur)) {
                cout<<"swapping "<<*first<<" and "<<*cur<<'\n';
                std::swap(*first, *cur);
            }
        }
    }
}

bool CompFunc(int a, int b) {
    return a < b;
}
struct Compobj{
    bool operator()(int a, int b){
        return a < b;
    }
};
int main() {
    int arr[]={2, 1, 2, 7, 3};
    Sort(arr, arr + 4, CompFunc);
    for(auto i:arr){
        cout<<i<<' ';
    }
    return 0;
}
