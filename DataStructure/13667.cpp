#include<bits/stdc++.h>
using namespace std;
int main(){
    int participants, matches;
    cin>>participants>>matches;
    vector<int> team(participants+5, 0);
    for(int i=0;i<matches;i++){
        int x,y; cin>>x>>y;
        if(team[x] == 0 && team[y] == 0){
            team[x] = 1;
            team[y] = 2;
            cout<<"YES\n";
        }else if(team[x] == 0){
            if(team[y] == 1) team[x] = 2;
            else team[x] = 1;
            cout<<"YES\n";
        }else if(team[y] == 0){
            if(team[x] == 1) team[y] = 2;
            else team[y] = 1;
            cout<<"YES\n";
        }else if(team[x] == team[y]){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}