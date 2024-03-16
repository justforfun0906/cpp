#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = s.length();
    int temp = 0;
    int flag = 1;
    int cnt =0;
    for(int i=0;i<len;i++){
        if(s[i]=='<'){
            temp++;
            cnt++;
        }
        if(s[i]=='>'){
            temp--;
            cnt++;
        }
        if(temp<0){
            flag = 0;
            break;
        }
    }
    if(temp!=0||cnt == 0) flag = 0;
    flag?cout<<"Yes\n":cout<<"No\n";
}