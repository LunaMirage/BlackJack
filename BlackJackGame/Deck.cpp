#pragma once
#include "StdAfx.h"
#include "Deck.h"
using namespace std;

Deck::Deck()
{
	suits[0] = "Hearts";
	suits[1] = "Diamonds";
	suits[2] = "Clubs";
	suits[3] = "Spades";
	index = 51;
}

void Deck::buildDeck(){
	for(int j=0;j<4;j++)							//OJBECTS!!!!
		for(int i=1; i<14; i++){
			cards.push_back(Card(suits[j],i));
		}
}

void Deck::shuffleDeck(){
      int card;
	  int randNum;
	  srand((unsigned)time(0)); 
      for (card = 0; card < 52; card++)
      {
			Card temporary;							//Temp card
            randNum = rand() % 52;
            temporary = cards[card];
			cards[card] = cards[randNum];
            cards[randNum] = temporary;
	  }
}

Card Deck::deal(){
	Card temporary(cards[index].getSuit(),cards[index].getNum());
	cards.pop_back();
	index--;
	return temporary;
}


Deck::~Deck()
{
}

int show;