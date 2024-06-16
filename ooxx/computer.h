#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
using namespace std;
class Computer {
public:
    Computer();

    void Play();

private:
    vector<vector<char>> board;
    char player;
    char computer;
    bool gameover;

    void DrawBoard() const;
    void PlayerMove();
    void ComputerMove();
    bool IsValidMove(int row, int col) const;
    bool CheckWin(char player) const;
    bool IsFull() const;
};

#endif  // COMPUTER_H
