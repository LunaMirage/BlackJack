#pragma once
#include "StdAfx.h"
#include "Card.h"


Card::Card(string sv, int val)
{
	suit = sv;
	value = val;
}

Card::Card(){
	suit = "hearts";
	value = 1;
}

int Card::getNum(){
	return value;
}

string Card::getSuit(){
	return suit;
}

Card::~Card(void)
{
}