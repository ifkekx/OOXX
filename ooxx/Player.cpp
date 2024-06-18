#include"Player.h"

Player::Player()
{
    this->cards = new Card[5];
    win = 0;
    money = 10000;
    inPlay = true;
}
void Player::setCards(Card* cards)
{
    for (int i = 0; i < 5; ++i)
        this->cards[i] = cards[i];
}

void Player::setCstyle(int v)
{
    cStyle = v;
}

int Player::getCstyle()
{
    return cStyle;
}

Card* Player::getCards()
{
    return cards;
}

bool Player::getWin()
{
    return win;
}

void Player::setWin(bool w)
{
    win = w;
}

void Player::setMoney(int money)
{
    this->money = money;
}

int Player::getMoney()
{
    return money;
}

void Player::setStakeMoney(int stakeMoney)
{
    this->stakeMoney = stakeMoney;
}

int Player::getStakeMoney()
{
    return stakeMoney;
}

void Player::setInPlay(bool value)
{
    inPlay = value;
}

bool Player::getInPlay()
{
    return inPlay;
}

void Player::winMoney()
{
    if (cStyle == 1)
        money += stakeMoney;
    else if (cStyle == 2)
        money += stakeMoney * 2;
    else if (cStyle == 3)
        money += stakeMoney * 3;
    else if (cStyle == 4)
        money += stakeMoney * 5;
}

void Player::loseMoney()
{
    if (cStyle == 0)
        money -= stakeMoney;
    else if (cStyle == 1)
        money -= stakeMoney * 2;
    else if (cStyle == 2)
        money -= stakeMoney * 3;
    else if (cStyle == 3)
        money -= stakeMoney * 4;
    else if (cStyle == 4)
        money -= stakeMoney * 6;
}
