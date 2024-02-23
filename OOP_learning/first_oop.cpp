#include<iostream>
using namespace std;
class Number{
    int num;
    public:
    Number(int n){
        num = n;
    }
    void show(){
        cout << num << endl;
    }
};
int main(){
    int temp;
    cin>>temp;
    Number a(temp);
    a.show();
}
