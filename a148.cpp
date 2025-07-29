#include<iostream>
using namespace std;
int main(){
    int n;
    //boolean true false
    while(cin>>n){
        //n input ->make a for loop, n times
        //create a counter variable, set it as 0
        //inside for loop, get a input number into a temporary variable
        //add it into counter variable.
        //i=0,k=61 -> i=1,k=61 -> i=2,k=61 -> i=3,k=61 -> i=4,k=55
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int k; cin>>k;
            cnt+=k;
            cout<<"now i= "<<i<<" input = "<<k<<" cnt = "<<cnt<<endl;
        }
        
        cout<<cnt;
    }
}