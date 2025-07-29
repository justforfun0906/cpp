#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int MAX=0;
    int i = 0;
    while(i < 3){
        cin>>a[i];
        i++;//i=i+1, i+=1
    }
    i = 0;
    while(i < 3){
        cout << a[i] << " ";
        cout<<"now i = "<<i<<endl;
        i++;  
    }
}