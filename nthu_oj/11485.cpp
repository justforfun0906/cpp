#include<bits/stdc++.h>
using namespace std;
/*void insert();
void output();
void range_out();*/
int decode(const vector<int> &v);
struct cmp{
    bool operator()(const vector<int> &a,const vector<int> &b)const{
        return decode(a)<decode(b);
    }
};
set<vector<int>, cmp> S;
int main(){
    string cmd;
    while(cin>>cmd){
        if(cmd=="insert"){

        } else if(cmd=="output"){

        } else if(cmd=="range_out"){

        }
    }
}
void insert(){

}
void range_out(){

}
void output(){

}
int decode(const vector<int> &v){
    int ret = 0;
    int size = v.size();
    for(int i=0;i<size;i++){
        ret += v[i]*(size-i);
    }
    return ret;
}