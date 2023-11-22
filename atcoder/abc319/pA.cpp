#include<iostream>
#include<string>
using namespace std;
int main(){
    int rating[10] = {3858,3679,3658,3648,3630,3613,3555,3516,3481};
    string handle[10] = {"tourist", "ksun48", "Benq", "Um_nik", "apiad", "Stonefeang", "ecnerwala", "mnbvmar", "newbiedmy", "semiexp"};
    string temp; cin>>temp;
    for(int i=0;i<10;i++){
        if(handle[i]==temp)cout<<rating[i];
    }
}