#pragma once
#include <string>
#include <vector> 
using namespace std;
class Card
{
private:
	string suit;
	int value;

public:
	int getNum();
	string getSuit();
	Card(string sv,int val);
	Card();
	//Card(Card &c);
	~Card(void);
};