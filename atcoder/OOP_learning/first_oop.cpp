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
    Number operator+(const Number &n){
        return Number(this->a+n.a,this->b+n.b);
    }
    void print(){
        cout<<"printing "<<this->show()<<endl;
    }

};
istream &operator>>(std::istream &in, Number &n){
    in >> n.a >> n.b;
    return in;
}
ostream &operator<<(std::ostream &out, Number &n){
    out << n.a << " " << n.b;
    return out;
}
int main(){
    Number n1(1,2),n2(3,4),n3(5,6);
    cout<<n1<<" "<<n2<<endl;
    n1 = n1+n2+n3;
    cout<<n1<<" "<<n2<<endl;
    return 0;
}