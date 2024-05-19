#include<bits/stdc++.h>
using namespace std;
void insert();
void output();
void range_out();
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
            insert();
        } else if(cmd=="output"){
            output();
        } else if(cmd=="range_out"){
            range_out();
        }
    }
}
vector<int> get_input(){
    int n;
    vector<int> ret;
    while(cin>>n&&n!=0){
        ret.push_back(n);
    }
    return ret;
}
void insert(){
    vector<int> seq = get_input();
    int key_val = decode(seq);
    for(auto it:S){
        if(decode(it)==key_val){
            cout<<"exist\n";
            S.erase(it);
            vector<int> tmp;
            for(auto i=seq.rbegin();i!=seq.rend();i++){
                tmp.push_back(*i);
            }
            seq = tmp;
            break;
        }
    }
    S.insert(seq);
}
void range_out(){
    vector<int> first_seq = get_input();
    /*for(auto it:first_seq){
        cout<<it<<' ';
    }
    cout<<'\n';*/
    vector<int> second_seq = get_input();
    /*for(auto it:second_seq){
        cout<<it<<' ';
    }
    cout<<'\n';*/
    int first_key = decode(first_seq);
    int second_key = decode(second_seq);
    for(auto it:S){
        int key = decode(it);
        if(key>=first_key&&key<=second_key){
            for(auto i:it){
                cout<<i<<' ';
            }
            cout<<'\n';
        }
    }
}
void output(){
    for(auto it:S){
        for(auto i:it){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
}
int decode(const vector<int> &v){
    int ret = 0;
    int size = v.size();
    for(int i=0;i<size;i++){
        ret += v[i]*(size-i);
    }
    return ret;
}