#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iostream>
using namespace std;

const int TIC_TAC_TOW_ROWS = 3;
const int TIC_TAC_TOW_COLS = 3;
const int CONNECT_FOUR_ROWS = 6;
const int CONNECT_FOUR_COLS = 7;

class Move;
class Board;
class TicTacToeBoard;
class ConnectFourBoard;

class Move {
    protected:
        string player;
        string move;

    public:
        Move() : player(""), move("") {}
        Move(string p, string m) : player(p), move(m) {}
        string getPlayer() { return player; }
        friend class TicTacToeBoard;
        friend class ConnectFourBoard;
        friend istream& operator>>(istream& input, Move& m) {
            string moveStr;
            input >> moveStr;
            size_t colonPos = moveStr.find(':');
            if (colonPos != std::string::npos) {
                m.player = moveStr.substr(0, colonPos);
                m.move = moveStr.substr(colonPos + 1);
            }
            return input;
        }
};

class Board {
    private:
        char** board;
        int rows;
        int cols;
        
    protected:
        int gameTurn;
        int nextPlayer() { return (gameTurn + 1) % 2; }

        /* === TODO:_01 === */
        // Constructor that initializes the board with specified rows and columns.
        Board(int r, int c):rows(r), cols(c), gameTurn(0){
            // Initialize the board with dots.
            board = new char*[rows];
            for (int i = 0; i < rows; ++i) {
                board[i] = new char[cols];
                for (int j = 0; j < cols; ++j) {
                    board[i][j] = '.';
                }
            }   
        }

        /* === TODO:_02 === */
        // Copy constructor to create a deep copy of an existing board.
        Board(const Board& b):rows(b.rows), cols(b.cols), gameTurn(b.gameTurn){
            board = new char*[rows];
            for (int i = 0; i < rows; ++i) {
                board[i] = new char[cols];
                for (int j = 0; j < cols; ++j) {
                    board[i][j] = b.board[i][j];
                }
            }
        }

        /* === TODO:_03 === */
        // Subscript operator to access a row of the board directly,
        // gives access to the character at the specified index.
        char* operator[](int idx){//returning a char array pointer
            return board[idx];
        }

    public:
        Board() : board(nullptr), rows(0), cols(0), gameTurn(0) {}

        /* === TODO:_04 === */
        // Destructor to clean up dynamically allocated memory for the board.
        ~Board(){
            for (int i = 0; i < rows; ++i) {
                delete[] board[i];
            }
            delete[] board;
        }

        // To determine if a game has been won.
        virtual bool isGameWon() = 0;

        // To create and return a clone of the current board.
        virtual Board* clone() const = 0;

        // To apply a move to the board and return the updated board.
        virtual Board& operator+=(const Move& m) = 0;

        /* === TODO:_05 === */
        // Provide ostream support for printing the board.
        friend ostream& operator<<(ostream& output, const Board& b){
            for (int i = 0; i < b.rows; ++i) {
                for (int j = 0; j < b.cols; ++j) {
                    output << b.board[i][j];
                }
                //if not the last row, print a new line
                if(i+1<b.rows) output << endl;
            }
            return output;
        }
};

class TicTacToeBoard : public Board {
    public:
        // Returns a new instance of a TicTacToeBoard that is a copy of the current board.
        TicTacToeBoard* clone() const override { return new TicTacToeBoard(*this); }

        /* === TODO:_06 === */
        // Constructor to initialize a TicTacToeBoard with the board size of 3x3.
        TicTacToeBoard():Board(TIC_TAC_TOW_ROWS, TIC_TAC_TOW_COLS){}

        /* === TODO:_07 === */
        // Applies a move to the board, 
        // alternating between players ( gameTurn = nextPlayer(); ).
        TicTacToeBoard& operator+=(const Move& m) override{
            //get the row and column from the move
            //move:1/0 or 1/1 or 2/2...
            int row = m.move[0] - '0';
            int col = m.move[2] - '0';
            //update the board
            //board[] operator gives the whole row
            (*this)[row][col] = gameTurn == 0 ? 'X' : 'O';
            //switch the player
            //nextPlayer is a function in the base class
            gameTurn = nextPlayer();
            return *this;
        }

        /* === TODO:_08 === */
        // Checks rows, columns, and diagonals 
        // to determine if the TicTacToe game is won.
        bool isGameWon() override{
            //check rows first
            for(int i=0;i<3;i++){
                if((*this)[i][0] != '.' && (*this)[i][0] == (*this)[i][1] && (*this)[i][1] == (*this)[i][2]){
                    return true;
                }
            }
            //check columns
            for(int i=0;i<3;i++){
                if((*this)[0][i] != '.' && (*this)[0][i] == (*this)[1][i] && (*this)[1][i] == (*this)[2][i]){
                    return true;
                }
            }
            //check diagonals
            //top-left to bottom-right
            if((*this)[0][0] != '.' && (*this)[0][0] == (*this)[1][1] && (*this)[1][1] == (*this)[2][2]){
                return true;
            }
            //top-right to bottom-left
            if((*this)[0][2] != '.' && (*this)[0][2] == (*this)[1][1] && (*this)[1][1] == (*this)[2][0]){
                return true;
            }
            return false;
        }
};

class ConnectFourBoard : public Board {
    public:
        // Returns a new instance of a ConnectFourBoard that is a copy of the current board.
        ConnectFourBoard* clone() const override { return new ConnectFourBoard(*this); }

        /* === TODO:_09 === */
        // Constructor to initialize a ConnectFourBoard with the board size of 6x7.
        ConnectFourBoard():Board(CONNECT_FOUR_ROWS, CONNECT_FOUR_COLS){}

        /* === TODO:_10 === */
        // Applies a move to the board, 
        // alternating between players ( gameTurn = nextPlayer(); ).
        ConnectFourBoard& operator+=(const Move& m) override;

        /* === TODO:_11 === */
        // Checks for four consecutive pieces horizontally, vertically, and diagonally
        // to determine if the ConnectFour game is won.
        bool isGameWon() override;
};

#endif
