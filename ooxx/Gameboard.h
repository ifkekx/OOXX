#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {
public:
    GameBoard(); 
    void printBoard(); // 遊戲板
    bool makeMove(int row, int col, char player); // 玩家進行遊戲動作
    bool isFull(); 
    bool checkWin(); 

private:
    char board[3][3]; 
};

#endif 
