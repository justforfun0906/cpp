#include "function.h"
#include<bits/stdc++.h>
using namespace std;
int Board::getSize(){
    return size;
}
void Board::set(int i, int j, int x){
    board[i][j] = x;
}
int Board::get(int i, int j){
    return board[i][j];
}
bool GomokuGame::place(int player, string location){
    int x = location[0] - '0';
    int y = location[1] - '0';
    if(gomokuBoard->get(x, y) == 0&&this->turn == player){
        gomokuBoard->set(x, y, player);
        return true;
    }
    return false;
}
bool GomokuGame::remove(int player, string location){
    int x = location[0] - '0';
    int y = location[1] - '0';
    if(gomokuBoard->get(x, y) != 0&&this->turn == player){
        gomokuBoard->set(x, y, 0);
        return true;
    }
    return false;
}
int GomokuGame::getWinner(){//return 0 if no winner, 1 if Doraemon wins, 2 if DebugCatCapoo wins
    for(int i = 0; i < gomokuBoard->getSize(); ++i){
        for(int j = 0; j < gomokuBoard->getSize(); ++j){
            if(gomokuBoard->get(i, j) != 0){
                int player = gomokuBoard->get(i, j);
                for(int dx = -1; dx <= 1; ++dx){
                    for(int dy = -1; dy <= 1; ++dy){
                        if(dx == 0 && dy == 0) continue;
                        int cnt = 1;
                        for(int k = 1; k < 5; ++k){
                            int x = i + dx * k;
                            int y = j + dy * k;
                            if(x < 0 || x >= gomokuBoard->getSize() || y < 0 || y >= gomokuBoard->getSize()) break;
                            if(gomokuBoard->get(x, y) == player) cnt++;
                            else break;
                        }
                        if(cnt == 5) return player;
                    }
                }
            }
        }
    }
    return 0;
}