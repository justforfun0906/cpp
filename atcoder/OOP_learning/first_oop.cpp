#include<iostream>
using namespace std;
struct st{
    int a;
    int b;
};
class Number{
    int num;
    friend std::istream &operator>>(istream &in,Number &n);
    public:
    int a,b;
    Number(int a,int b){
        this->a=a;
        this->b=b;
    }
    int show(){
        return 2*a+3*b;
    }
    void print(){
        cout<<"printing "<<this->show()<<endl;
    }

};
istream &operator>>(std::istream &in, Number &n){
    in >> n.a >> n.b;
    return in;
}
int main(){
    Number n(2,3);
    n.print();
}