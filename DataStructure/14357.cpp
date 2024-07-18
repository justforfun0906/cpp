#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    list<int> li;
    li.push_back(0);
    list<int>::iterator iter = li.begin();
    for(int i=0;i<n;i++){
        char ins = s[i];
        if(ins == 'L'){
            if(iter != li.begin()){
                li.insert(iter,i+1);
                iter--;
            }else{
                li.push_front(i+1);
                iter = li.begin();
            }
        }else if(ins == 'R'){
            if(iter != li.end()){
                iter++;
                li.insert(iter,i+1);
                iter--;
            }else{
                li.push_back(i+1);
                iter = li.end();
                iter--;
            }
        }
    }
    for(auto i:li){
        if(i!=li.back())cout<<i<<' ';
        else cout<<i;
    }
    cout<<'\n';
}