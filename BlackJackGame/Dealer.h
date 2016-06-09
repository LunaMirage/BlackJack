#pragma once
#include "Card.h"
#include "Player.h"
class Dealer:public Player
{
private:
	string name;

public:
	Dealer(string host);
	Dealer();
	void startingHand();
	string dealerName();
	~Dealer(void);
};