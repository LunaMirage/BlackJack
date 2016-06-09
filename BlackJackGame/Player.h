#pragma once
#include "Card.h"
#include "Deck.h"
#include <iostream>

class Player
{
private:
	string playerName;
	string name;

protected:
	Card hand[5];
	int index;
	bool ace;

public:
	Player(string name);
	string getName();
	int cardsInHand();
	Player();
	void clearHand();
	int handValue();
	void hit(Card temporary);
	void displayHand();
	~Player(void);
};