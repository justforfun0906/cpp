#include "function.h"
#include <iostream>
Board::Board(int r, int c): rows(r), cols(c), gameTurn(0){
    board = new char*[rows];
    for(int i=0;i<rows;i++){
        board[i] = new char[cols];
        for(int j=0;j<cols;j++){
            board[i][j] = '.';
        }
    }
}
Board::Board(const Board& b): rows(b.rows), cols(b.cols), gameTurn(b.gameTurn){
    board = new char*[rows];
    for(int i=0;i<rows;i++){
        board[i] = new char[cols];
        for(int j=0;j<cols;j++){
            board[i][j] = b.board[i][j];
        }
    }
}
char* Board::operator[](int idx){
    return board[idx];
}
Board::~Board(){
    for(int i=0;i<rows;i++){
        delete[] board[i];
    }
    delete[] board;
}
ostream& operator<<(ostream& output, const Board& b){
    for(int i=0;i<b.rows;i++){
        for(int j=0;j<b.cols;j++){
            output << b.board[i][j];
        }
        if(i+1<b.rows)output << endl;
    }
    return output;
}
//derived class constructors
TicTacToeBoard::TicTacToeBoard(): Board(TIC_TAC_TOW_ROWS, TIC_TAC_TOW_COLS){}
ConnectFourBoard::ConnectFourBoard(): Board(CONNECT_FOUR_ROWS, CONNECT_FOUR_COLS){}
TicTacToeBoard& TicTacToeBoard::operator+=(const Move& m){
    int row = m.move[0]-'0';
    int col = m.move[2]-'0';
    (*this)[row][col] = gameTurn?'X':'O';
    gameTurn= nextPlayer();
    return *this;
}
bool TicTacToeBoard::isGameWon(){
    //check rows and columns
    for(int i=0;i<TIC_TAC_TOW_ROWS;i++){
        if((*this)[i][0]!='.' &&
        (*this)[i][0]==(*this)[i][1] &&
        (*this)[i][1]==(*this)[i][2])return true;
    }
    for(int i=0;i<TIC_TAC_TOW_COLS;i++){
        if((*this)[0][i]!='.' &&
        (*this)[0][i]==(*this)[1][i] &&
        (*this)[1][i]==(*this)[2][i])return true;
    }
    //check diagonals
    if((*this)[0][0]!='.' && 
        (*this)[0][0]==(*this)[1][1] && 
        (*this)[1][1]==(*this)[2][2]) return true;

    if((*this)[0][2]!='.' && 
        (*this)[0][2]==(*this)[1][1] && 
        (*this)[1][1]==(*this)[2][0]) return true;
    return false;
}
ConnectFourBoard& ConnectFourBoard::operator+=(const Move& m){
    int col = m.move[1]-'0';
    for(int i = CONNECT_FOUR_ROWS-1;i>=0;i--){
        if((*this)[i][col]=='.'){
            (*this)[i][col] = gameTurn?'B':'W';
            break;
        }
    }
    gameTurn = nextPlayer();
    return *this;
}
bool ConnectFourBoard:: isGameWon(){
    //check rows
    for(int i=0;i<CONNECT_FOUR_ROWS;i++){
        for(int j=0;j<CONNECT_FOUR_COLS-3;j++){
            if((*this)[i][j]!='.' && (*this)[i][j]==(*this)[i][j+1] && (*this)[i][j+1]==(*this)[i][j+2] && (*this)[i][j+2]==(*this)[i][j+3])return true;
        }
    }
    //check columns
    for(int i=0;i<CONNECT_FOUR_ROWS-3;i++){
        for(int j=0;j<CONNECT_FOUR_COLS;j++){
            if((*this)[i][j]!='.' && (*this)[i][j]==(*this)[i+1][j] && (*this)[i+1][j]==(*this)[i+2][j] && (*this)[i+2][j]==(*this)[i+3][j])return true;
        }
    }
    //check diagonals
    for(int i=0;i<CONNECT_FOUR_ROWS-3;i++){
        for(int j=0;j<CONNECT_FOUR_COLS-3;j++){
            if((*this)[i][j]!='.' && (*this)[i][j]==(*this)[i+1][j+1] && (*this)[i+1][j+1]==(*this)[i+2][j+2] && (*this)[i+2][j+2]==(*this)[i+3][j+3])return true;
        }
    }
    for(int i=0;i<CONNECT_FOUR_ROWS-3;i++){
        for(int j=3;j<CONNECT_FOUR_COLS;j++){
            if((*this)[i][j]!='.' && (*this)[i][j]==(*this)[i+1][j-1] && (*this)[i+1][j-1]==(*this)[i+2][j-2] && (*this)[i+2][j-2]==(*this)[i+3][j-3])return true;
        }
    }
    return false;
}