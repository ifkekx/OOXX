﻿#include<string>
#include "player.h"
using namespace std;

Player::Player(string name, char symbol) {
    this->name = name;
    this->symbol = symbol;
}

string Player::getName() {
    return name;
}

char Player::getSymbol() {
    return symbol;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setSymbol(char symbol) {
    this->symbol = symbol;
}
