#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    b=a;
    int arr[a];

    for(int i=2;i<=a;i++){
        arr[i] = 0;
        while(a%i == 0){
            a = a/i;
            arr[i] += 1;
        }
    }
    for(int i=2;i<b;i++){
        if(arr[i]!=0){
            cout<<i<<'^'<<arr[i]<<'*';
        }
    }
    //[0, 2, 0, 0, 1, 0, 0, .....]-> 2^2 * 5
}