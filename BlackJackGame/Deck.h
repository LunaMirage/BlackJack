#pragma once
#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Deck
{
private:
	vector<Card> cards;			// Deck of Cards
	string suits[4];
	int index;

public:
	void buildDeck();
	void shuffleDeck();
	Card deal();
	Deck();
	~Deck();
};