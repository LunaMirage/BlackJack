#pragma once
#include "StdAfx.h"
#include "Player.h"

Player::Player(string actualName)
{
	name = actualName;			//Sets player name to what the user type in
	index = 0;
	ace = false;
}

Player::Player(){
	index = 0;
	ace = false;
}

int Player::cardsInHand(){
	return index;
}

void Player::displayHand(){
	int temp = 0;
	int num = 0;
	while(temp < index){
		num = hand[temp].getNum();
		if(num == 1)
			cout << "Ace of"   << "  " << hand[temp].getSuit() << "  ";
		else if(num == 11)
			cout << "Jack of"  << "  " << hand[temp].getSuit() << "  ";
		else if(num == 12)
			cout << "Queen of" << "  " << hand[temp].getSuit() << "  ";
		else if(num == 13)
			cout <<  "King of" << "  " << hand[temp].getSuit() << "  ";
		else
			cout << hand[temp].getNum() << " " << " of " << hand[temp].getSuit() << "  ";
		if((temp+1) != index )
			cout << ", ";
		temp++;
	}
	cout << "(" << handValue() << ") " << endl;
}

void Player::hit(Card temporary){ // Card temporary
	hand[index] = temporary;
	index++;				// One more then number of cards in hand
}

int Player::handValue(){
	int temp = 0;
	int value = 0;
	bool ace = false;
	int num;						// Cards number
	while(temp < index){
		num = hand[temp].getNum();							// Number is equal to ace value
		if(num == 11)
			num = 10;						// Jack is 10
		else if(num == 12)
			num = 10;						// Queen is 10
		else if(num == 13)
			num = 10;						// King is 10
		if(num==1)
			ace = true;
		value = value + num;
	temp++;
	}
	// Researches for an ace
	// Value is redeclared each time, causing ace to revert past 9
	if((value <= 11) && (ace == true)){
		value = value + 10;
	}
	return value;
}

string Player::getName(){
	return name;
}

void Player::clearHand(){
	index = 0;
}

Player::~Player(void)
{
}
