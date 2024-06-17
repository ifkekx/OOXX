
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
            cout << setw(70) << "|        ���ߪ��a���       |" << endl;
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
            cout << setw(70) << "|         �q�����          |" << endl;
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
            cout << setw(70) << "|           �M��            |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "|                           |" << endl;
            cout << setw(70) << "=============================" << endl;
            gameover = true;
        }
        player = (player == 'O') ? 'X' : 'O'; // �������a

    }
}

void Computer::DrawBoard() const {
    system("cls");
    cout << "�w��Ө줫�r�C��" << endl;
    cout << "�C���W�h:�b�C����������ݪ��u���v�r�Ÿ��A�@���E��C";
    cout << "�Ѫ��a����";
    cout << "�Y�E��e���A���觡�L�k�s���@�u�A�Y���M���C" << endl;
    cout << "���a1��: O | �q����: X" << endl;
    cout << endl;
    cout << "[0,0]|[0,1]|[0,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[1,0]|[1,1]|[1,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[2,0]|[2,1]|[2,2]" << endl;
    cout << "�H�W���C�ӭӤl���Ʀr!!" << endl;
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
        cout << "��J���~�A�Э���" << endl;
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
        return false; // �W�X�d��
    }
    return board[row][col] == ' '; // ��m�O�_����
}

bool Computer::CheckWin(char player) const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // ��ۦP
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // �C�ۦP
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {   // �ˬd�﨤�u
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
