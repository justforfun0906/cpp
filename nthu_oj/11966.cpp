#include<bits/stdc++.h>
using namespace std;
string par="{}[]()<>";
int main(){
    int q; cin>>q;
    int i=1, ans = 1;
    getchar();
    stack<char> s;
    while(i<=q){
        //since the string might be empty, we need to use getchar() to read the input
        char c = getchar();
        if(c=='\n'||c==EOF){
            cout<<"Case "<<i<<": ";
            if(s.empty()&&ans==1){
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }
            ans = 1;
            i++;
            while(!s.empty()){
                s.pop();
            }//reset the stack
            continue;
        }
        if(par.find(c)%2==0){
            s.push(c);//push the left part of the pair
        } else {//right parenthesis
            if(s.empty()){//no corresponding left parenthesis
                ans = 0;
            } else {
                if(par.find(s.top())+1==par.find(c)){//has corresponding left parenthesis
                    s.pop();
                } else {//no corresponding left parenthesis
                    ans = 0;
                }
            }
        }
    }
}