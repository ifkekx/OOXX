
#include "Computer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;

Computer::Computer() {
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    player = 'O';
    computer = 'X';
    gameover = false;
}

void Computer::Play() {
    while (!gameover) {
        DrawBoard();
        if (player == 'O') {
            PlayerMove();
        }
        else {
            ComputerMove();
        }

        if (CheckWin(player)) {
            DrawBoard();
            system("cls");
            cout << setw(70) << "=============================" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|        恭喜玩家獲勝       |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "=============================" << endl;
            gameover = true;
        }
        else if (CheckWin(computer)) {
            DrawBoard();
            system("cls");
            cout << setw(70) << "=============================" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|         電腦獲勝          |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "=============================" << endl;
            gameover = true;
        }
        else if (IsFull()) {
            DrawBoard();
            system("cls");
            cout << setw(70) << "=============================" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|           和局            |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "=============================" << endl;
            gameover = true;
        }
        player = (player == 'O') ? 'X' : 'O'; // 切換玩家

    }
}

void Computer::DrawBoard() const {
    system("cls");
    cout << "歡迎來到井字遊戲" << endl;
    cout << "遊戲規則:在遊戲版有兩橫兩豎的「井」字符號，共有九格。";
    cout << "由玩家先攻";
    cout << "若九格畫完，雙方均無法連成一線，即為和局。" << endl;
    cout << "玩家1為: O | 電腦為: X" << endl;
    cout << endl;
    cout << "[0,0]|[0,1]|[0,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[1,0]|[1,1]|[1,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[2,0]|[2,1]|[2,2]" << endl;
    cout << "以上為每個個子的數字!!" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void Computer::PlayerMove() {
    int row, col;
    cin >> row;
    cin >> col;

    if (IsValidMove(row, col)) {
        board[row][col] = player;
    }
    else {
        cout << "輸入錯誤，請重試" << endl;
        PlayerMove();
        
    }
}

void Computer::ComputerMove() {
    srand(time(0));
    int row, col;

    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!IsValidMove(row, col));

    board[row][col] = computer;
}

bool Computer::IsValidMove(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false; // 超出範圍
    }
    return board[row][col] == ' '; // 位置是否為空
}

bool Computer::CheckWin(char player) const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // 行相同
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // 列相同
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {   // 檢查對角線
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return true;
    }
    return false;
}

bool Computer::IsFull() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}
