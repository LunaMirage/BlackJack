#pragma once
#include "StdAfx.h"
#include "Dealer.h"

Dealer::Dealer(string host)
{
	name = "host";
}

Dealer::Dealer(){
	name = "House";
}

void Dealer::startingHand(){
	int temp = 0;
	int num = 0;
	while(temp < index){
		num = hand[temp].getNum();
		if(temp >= 1){
			if(num == 1)
				cout << "Ace of"   << "  " << hand[temp].getSuit() << "  ";
			else if(num == 11)
				cout << "Jack of"  << "  " << hand[temp].getSuit() << "  ";
			else if(num == 12)
				cout << "Queen of" << "  " << hand[temp].getSuit() << "  ";
			else if(num == 13)
				cout <<  "King of" << "  " << hand[temp].getSuit() << "  ";
			else
				cout << hand[temp].getNum() << " " << " of " << hand[temp].getSuit();
			if(temp == 0)
				cout << ", ";
		}
		else
			cout << " Face Down Card, Revealing a: ";
		temp++;
	}
	cout << endl;
}

string Dealer::dealerName(){
	return name;
}

Dealer::~Dealer(void)
{

}