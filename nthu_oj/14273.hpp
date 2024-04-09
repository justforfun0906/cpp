#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <string>
using namespace std;

class Board {
    private:
        int** board;
        int size;

    public:
        Board(int n) : size(n) {//assign size to n
            board = new int*[size];
            for(int i = 0; i < size; ++i) {
                board[i] = new int[size];
                for(int j = 0; j < size; ++j) {
                    board[i][j] = 0;
                }
            }
        }

        ~Board() {
            for(int i = 0; i < size; ++i) {
                delete[] board[i];
            }
            delete[] board;
        }

        void showBoard() {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (!board[i][j]) cout << ".";
                    else cout << (board[i][j] == 1 ? "O" : "X");
                }
                cout << "\n";
            }
            cout << "\n";
        }

        /* TODO(done): Get the size of the board */
        int getSize();

        /* TODO(done): Set the value of board[i][j] to x */
        void set(int i, int j, int x);

        /* TODO(done): Get the value of board[i][j] */
        int get(int i, int j);
};
int Board::getSize(){
    return size;
}
void Board::set(int i, int j, int x){
    board[i][j] = x;
}
int Board::get(int i, int j){
    return board[i][j];
}
class GomokuGame {
    private:
        Board* gomokuBoard;
        int turn; // 1 -> Doraemon, 2 -> DebugCatCapoo

    public:
        GomokuGame(int n) {
            gomokuBoard = new Board(n);
            turn = 1;
        }

        ~GomokuGame() {
            delete gomokuBoard;
        }

        void showBoard() {
            gomokuBoard->showBoard();
        }

        void nextRound() {
            turn = (turn == 1 ? 2 : 1);
        }

        /* TODO: Place or remove the piece at the specified location
                 Return true if the operation completes successfully */
        bool place(int player, string location);
        bool remove(int player, string location);
    
        /* TODO: Return 1 if Doraemon wins, 2 if DebugCatCapoo wins,
                 or 0 if the game has not yet ended */
        int getWinner(); 
};    
bool GomokuGame::place(int player, string location){
    int x = location[0] - 'A';
    int y = location[1] - '1';
    if(gomokuBoard->get(x, y) == 0){
        gomokuBoard->set(x, y, player);
        return true;
    }
    return false;
}
bool GomokuGame::remove(int player, string location){
    int x = location[0] - 'A';
    int y = location[1] - '1';
    if(gomokuBoard->get(x, y) == player){
        gomokuBoard->set(x, y, 0);
        return true;
    }
    return false;
}
int GomokuGame::getWinner(){
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
#endif // FUNCTION_H