#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    short t;//team number;
    short scene = 1;
    while(cin>>t && t!=0){
        cout<<"Scenario #"<<scene++<<'\n';
        unordered_map<int, int> whichTeam; // Maps person ID to team number
        whichTeam.reserve(1000); // Reserve space to avoid rehashing
        int p;
        for(short i=1;i<=t;i++){
            cin>>p;
            int temp;
            for(short j=0;j<p;j++){
                cin>>temp;
                whichTeam[temp] = i; // Direct assignment is faster than insert
            }
        }
        vector<queue<int>> Queue_for_each_team(t+1);
        /*
        1: 
        2: 101
        3: 201 202
        4:
        ..
        .

        teamQueue: 2, 3,...
        */
        queue<short> teamQueue;
        char ins[10]; // Use char array instead of string for faster input
        while(cin>>ins && ins[0]!='S'){ // Compare first character instead of full string
            if(ins[0] == 'E'){ // Check first character instead of full string
                int temp;
                cin>>temp;
                int team = whichTeam[temp]; // Direct access is faster when we know element exists
                if(Queue_for_each_team[team].empty()){
                    teamQueue.push(team);
                }
                Queue_for_each_team[team].push(temp);
            }else{//DEQUEUE
                int frontTeam = teamQueue.front();
                cout<<Queue_for_each_team[frontTeam].front()<<'\n';
                Queue_for_each_team[frontTeam].pop();
                if(Queue_for_each_team[frontTeam].empty()){
                    teamQueue.pop();
                }
            }
        }
    }
}