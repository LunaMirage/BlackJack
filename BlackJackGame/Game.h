#pragma once
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>
class Game
{
private:
	vector<Player> table;		// List of players
	int numOfPlayers;
	Deck d1;
	Dealer host;

public:
	void run();
	void blackJack();
	Game(void);
	~Game(void);
};