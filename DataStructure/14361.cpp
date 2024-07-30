#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > subnodes(n+1);
    vector<int> pa(n+1);
    for(int i=1;i<=n;i++){
        cin>>subnodes[i].first>>subnodes[i].second;
        //first = left child, second = right child
        if(subnodes[i].first!=-1)pa[subnodes[i].first] = i;
        if(subnodes[i].second!=-1)pa[subnodes[i].second] = i;
        pa[i] = i;
    }
    int root_node = 0;
    for(int i=1;i<=n;i++){
        if(pa[i] == i){
            root_node = i;
            break;
        }
    }
    int now = root_node;
    while(subnodes[now].first != -1 && subnodes[now].second != -1){
        if(subnodes[now].second!=-1){
            now = subnodes[now].second;
        } else{
            now = subnodes[now].first;
        }
    }
    cout<<now;
}