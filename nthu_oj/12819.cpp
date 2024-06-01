#include<bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int goalRow[] = {-1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
const int goalCol[] = {-1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
const int goalarr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
const int MAX_MOVE = 80;
class state{
    public:
    int steps;
    int puzzle[4][4];
    int heuristic;//h()value
    int ex, ey; //position of the empty block
    int prevMove;//to prevent moving back and forth
    state(int arr[4][4]){//constructor
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                this->puzzle[i][j] = arr[i][j];
            }
        }
        this->ex = this->ey = -1;
        this->steps = 0;
        this-> prevMove = -1;//initially no prevMove
        setHeuristic();
    }
    state(const state &target){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                puzzle[i][j] = target.puzzle[i][j];
            }
        }
        steps = target.steps;
        ex = target.ex;
        ey = target.ey;
        heuristic = target.heuristic;
        prevMove = target.prevMove;
    }
    void setHeuristic() {
            int h = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (puzzle[i][j]) {
                        int goalX = goalRow[puzzle[i][j]];//get the corresponding target position for every value
                        int goalY = goalCol[puzzle[i][j]];
                        // Manhattan distance
                        h += abs(goalX - i) + abs(goalY - j);

                        // Linear conflict * 2
                        if (i == goalX) {//same row as its goalRow
                            for (int k = j; k < 4; k++) {
                                if (puzzle[i][k] > 0 && goalRow[puzzle[i][k]] == i && puzzle[i][j] > puzzle[i][k])
                                //having another tile on this row which is not blank,
                                //and it's also on its target row
                                //and these two tiles are blocking each other's way
                                h += 2;
                            }
                        }
                        if (j == goalY) {
                            for (int k = i; k < 4; k++) {
                                if (puzzle[k][j] > 0 && goalCol[puzzle[k][j]] == j && puzzle[i][j] > puzzle[k][j])
                                //linear conflict on column
                                h += 2;
                            }
                        }
                    }
                }
            }
        this->heuristic = h;
    }
    void update(int i, int newx, int newy){
        prevMove = i;
        swap(puzzle[newx][newy],puzzle[ex][ey]);
        ex = newx;
        ey = newy;
        steps++;
        setHeuristic();
    }
    bool operator<(const state& rhs) const {
        return steps+heuristic > rhs.steps+rhs.heuristic;
    }
};
int main(){
    int puzzle[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>puzzle[i][j];
        }
    }
    priority_queue<state> pq;
    state s(puzzle);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!puzzle[i][j]){
                s.ex = i;
                s.ey = j;
                break;
            }
        }
    }
    pq.push(s);
    while(!pq.empty()){
        state curState = pq.top();
        if(curState.heuristic == 0){//same as target -> win
            cout << curState.steps<<'\n';
            break;
        }
        pq.pop();

        /*if(curState.heuristic+curState.steps>MAX_MOVE){
            continue;
        }//what for?*/

        for(int i=0;i<4;i++){//going to new tile
            int newx = curState.ex + dx[i];
            int newy = curState.ey + dy[i];

            if(newx<0||newx>3||newy<0||newy>3){
                continue;
            }

            if(i == (curState.prevMove^1)){//wtf?
                continue;
            }
            state nextState = curState;
            nextState.update(i, newx, newy);
            pq.push(nextState);
        }
    }
    if (pq.empty()){
    //pq is empty but still can't find the solution
    //lose
        cout<<-1<<endl;
    }
}