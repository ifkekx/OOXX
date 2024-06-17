#include <iostream>
#include "Gameboard.h"
#include "Player.h"
#include"Computer.h"
#include<iomanip>
using namespace std;
void rule() {
    cout << "歡迎來到井字遊戲" << endl;
    cout << "遊戲規則:在遊戲版有兩橫兩豎的「井」字符號，共有九格。";
    cout << "兩位玩家，一個畫「○」，另一人畫「Ｘ」，輪流在九宮格上劃上自己的符號，最先連成一條線（直的、橫的、斜的都可）者為贏家。";
    cout << "若九格畫完，雙方均無法連成一線，即為和局。" << endl;
    cout << "玩家1為: O | 玩家2為: X" << endl;
    cout << endl;
    cout << "[0,0]|[0,1]|[0,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[1,0]|[1,1]|[1,2]" << endl;
    cout << "-----------------" << endl;
    cout << "[2,0]|[2,1]|[2,2]" << endl;
    cout << "以上為每個個子的數字!!";
}
void printGameStartPage() {
    cout << setw(70) << "=============================" << endl;
    cout << setw(70) << "|       Game Start          |" << endl;
    cout << setw(70) << "=============================" << endl;
    cout << setw(70) << "|                           |" << endl;
    cout << setw(70) << "|        歡迎來到           |" << endl;
    cout << setw(70) << "|        井字遊戲           |" << endl;
    cout << setw(70) << "|                           |" << endl;
    cout << setw(70) << "=============================" << endl;
    cout << setw(64) << "按下任何按鍵繼續";
    cin.get();
    cout << setw(60) << "遊戲開始" << endl;
}
void twoplayer() {
    GameBoard gameBoard; // 創建一個遊戲板物件
    Player player1("玩家1", 'O'); // 創建第一位玩家，用X表示
    Player player2("玩家2", 'X'); // 創建第二位玩家，用O表示
    int currentPlayer = 1; // 記錄目前是哪位玩家的回合
    gameBoard.printBoard(); // 初始畫面
    while (!gameBoard.isFull() && !gameBoard.checkWin()) {
        int row, col;
        if (currentPlayer == 1) { // 玩家1的回合
            system("cls");
            rule();
            cout << "接下來為玩家1" << endl;
            gameBoard.printBoard();
            cin >> row >> col;
            gameBoard.makeMove(row, col, 'O'); // 玩家1進行遊戲動作
            system("cls");
            gameBoard.printBoard(); // 顯示目前的遊戲板
            currentPlayer = 2; // 換到玩家2的回合
        }
        else { // 玩家2的回合
            system("cls");
            rule();
            cout << "接下來為玩家2" << endl;
            gameBoard.printBoard();
            cin >> row >> col;
            gameBoard.makeMove(row, col, 'X'); // 玩家2進行遊戲動作
            system("cls");
            gameBoard.printBoard(); // 顯示目前的遊戲板
            currentPlayer = 1; // 換到玩家1的回合
        }
    }
    // 結束遊戲
    if (gameBoard.checkWin()) {
        if (currentPlayer == 1)
            currentPlayer = 2;
        else currentPlayer = 1;
        system("cls");
        cout << setw(70) << "=============================" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(61) << "|         贏家為玩家" << currentPlayer << "       | " << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "|                           |" << endl;
        cout << setw(70) << "=============================" << endl;
    }
    else {
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
    }
}
void oneplayer() {
    Computer game;
    game.Play();
}
void chosemod() {
    int mod;
    cout << setw(63) << "請輸入遊玩模式" << endl;
    cout << setw(62) << "1.玩家VS電腦" << endl;
    cout << setw(62) << "2.玩家VS玩家" << endl;
    cin >> mod;
    if (mod == 1)
        oneplayer();
    else if (mod == 2)
        twoplayer();
    else {
        system("cls");
        cout << "輸入錯誤，請重試" << endl;
        chosemod();
    }
}
int main() {
    printGameStartPage();
    system("cls");
    chosemod();

}
