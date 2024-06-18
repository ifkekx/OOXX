#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    Player(string name, char symbol);
    string getName();
    char getSymbol();
    void setName(string name);
    void setSymbol(char symbol);

private:
    string name;
    char symbol;
};

#endif // PLAYER_H
