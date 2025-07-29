#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        string s[10];
        int score[10];
        int MAX = 0;
        for(int i=0;i<10;i++){
            cin>>s[i]>>score[i];
        }
        MAX = *max_element(score, score+10);
        cout<<"Case #"<<j<<":\n";
        for(int i=0;i<10;i++){
            if(score[i] == MAX){
                cout<<s[i]<<endl;
            }
        }
    }
}