#include<iostream>
using namespace std;
int main(){
    int N,M,K;
    int m = 0;
    cin>>N>>M>>K;
    if(K == 0 && N < 32 || K==1 && N < 55){
        cout<<"Wayne can't eat and drink.";
    }
    while(N>0){
        if(K == 0){//apple pie
            if(N>=32){
                N = N - 32;
                cout<<m*M;
                cout<<": Wayne eats an Apple pie, and now he ";
                if(N == 1){
                    cout<<"has 1 dollar.\n";
                }else if(N == 0){
                    cout<<"doesn't have money.\n";
                }else{
                    cout<<"has "<<N<<" dollars.\n";
                }
                K = 1;
                m = m + 1;
            }else{
                break;
            }
        }else{//corn soup
            if(N>=55){
                N = N -55;
                cout<<m*M;
                cout<<": Wayne drinks a Corn soup, and now he ";
                if(N == 1){
                    cout<<"has 1 dollar.\n";
                }else if(N == 0){
                    cout<<"doesn't have money.\n";
                }else{
                    cout<<"has "<<N<<" dollars.\n";
                }
                K = 0;
                m = m + 1;
            }else{
                break;
            }
        }
    }
}