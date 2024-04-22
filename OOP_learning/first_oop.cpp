#include<iostream>
using namespace std;
class Number{
    int num;
    public:
    Number(int n=3){
        num = n;
    }
    void show() const{
        cout << num << endl;
    }
};
int main(){
    Number n;
    n.show();

    return 0;
}
