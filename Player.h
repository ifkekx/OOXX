#ifndef P_H
#define P_H
#include"Card.h"

class Player
{
private:
	Card* cards;
	int cStyle;
	bool win;
	int money;
	int stakeMoney;
	bool inPlay;

public:
	Player();
	void setCards(Card*);
	void setCstyle(int);
	int getCstyle();
	Card* getCards();
	bool getWin();
	void setWin(bool);
	void setMoney(int);
	int getMoney();
	void setStakeMoney(int);
	int getStakeMoney();
	void setInPlay(bool);
	bool getInPlay();
	void winMoney();
	void loseMoney();
};
#endif