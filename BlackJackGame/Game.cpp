#pragma once
#include "StdAfx.h"
#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(void)
{
}

void Game::run(){
	int temp;
	string name;
	
	//Brief Intro 
	cout << "Welcome to Kevin's BlackJack Center" << endl;
	cout << endl;
	cout << "How many players? <1 - 7>: " << endl;
	cin >> numOfPlayers;

	// Handles number of players
	while(numOfPlayers > 7){
		cout << "The player count exceeds the number of seats at the table" << endl;
		cout << "Please enter in a new number of players" << endl;
		cin.clear();
		cin.sync();
		cin >> numOfPlayers;
	}

	// Handles players names
	temp = numOfPlayers;
	while(numOfPlayers > 0){
		cout << "Enter in player name: "<< endl;
		cin.clear();
		cin.sync();
		getline(cin,name);
		table.push_back(Player(name));
		cout << endl;
		numOfPlayers--;
	}
	numOfPlayers = temp;

	// Call to actual Black Jack game
	blackJack();
}

void Game::blackJack(){
	int temp = 0;
	char input;
	// Build and Shuffle Deck
	// Probably should break this into funtions, too lasy/tired
	d1.buildDeck();
	d1.shuffleDeck();

	// Players initial starting hands display
	while(temp < numOfPlayers){
	cout << table[temp].getName() << ":          ";
	table[temp].hit(d1.deal());
	table[temp].hit(d1.deal());	
	table[temp].displayHand();		// Breaks here
	temp++;
	}
	// Reset temp to 0 for later
	temp = 0;
	
	// Dealer
	cout << host.dealerName() << ":     ";
	host.hit(d1.deal());
	host.hit(d1.deal());
	host.startingHand();
	cout << endl;


	// Handles if any of the plays wish to hit or not
	while((table[temp].handValue() < 21) || (temp < numOfPlayers)){
		cin.clear();
		cin.sync();
		cout << table[temp].getName() << ",";
		cout << " do you want to hit? <y/n>: ";
		cin >> input;
		if(input == 'y'){
			table[temp].hit(d1.deal());
			table[temp].getName();
			table[temp].displayHand();
			if(table[temp].handValue() >= 21)
				temp++;
				if(temp == numOfPlayers)
						break;
			}
		else if(input == 'n'){
			temp++;	
			if(temp == numOfPlayers)
				break;
			continue;
			}
		else
			cout << " Please enter in n or y. " << endl;
		if(table[temp].handValue() > 21){
			cout << table[temp].getName() << "  busts."<< endl;
			temp++;
				if(temp == numOfPlayers)
					break;
			}
	}

	// Handles displaying the houses current hand and if they hit or not
	cout << host.dealerName() << ":          ";
	host.displayHand();
	while(host.handValue() < 17){
		host.hit(d1.deal());
		cout << host.dealerName() << ":     ";
		host.displayHand();
	}
	cout << endl;

	// Handles winnings/Busted/Losing
	for(temp = 0; temp<numOfPlayers;temp++){
		if((table[temp].handValue() >= host.handValue()) && (table[temp].handValue() < 22))
			cout << table[temp].getName() << ": Wins." << endl;
		else if((table[temp].handValue() < 22) && (host.handValue() > 21))
			cout << table[temp].getName() << " Wins." << endl;
		else if((host.handValue() < 22) && (table[temp].handValue() < host.handValue()))
			cout << table[temp].getName() << ": Lost." << endl;
		else if(table[temp].handValue() > 21)
			cout << table[temp].getName() << ": Lost,Busted." << endl;
		else
			cout << "WHAT DID I MISS?" << endl;
	}

	// Handles play again
	cout << endl;
	cout << "Do you want to play again? <y/n>: ";
	cin.clear();
	cin.sync();
	cin >> input;
	if(input == 'y'){
		for(temp = 0; temp<numOfPlayers;temp++)
			table[temp].clearHand();
		host.clearHand();
		blackJack();
	}
	cout << "Thank you for playing" << endl;
	cout << "Please hit enter to close" << endl;
}

Game::~Game(void)
{
}