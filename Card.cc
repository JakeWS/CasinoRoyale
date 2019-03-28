#include <iostream>
#include "Card.h"

using namespace std;

card::card()
{
	cout<<"Constructing card"<<endl;
	this->cardValue = 1;
	this->suit = 1;
}

card::card(short setValue, short setSuit)
{
	//cout<<"Constructing card"<<endl;
	this->cardValue = setValue;
	this->suit = setSuit;
}
/*
card::~card()
{
	cout<<"Deconstructing card"<<endl;
	
}
*/

short card::getValue()
{
	return this->cardValue;
}

string card::getSuit()
{
	if(this->suit == 0)
		return "Heart";
	else if(this->suit == 1)
		return "Clubs";
	else if(this->suit == 2)
		return "Diamond";
	else if(this->suit == 3)
		return "Spade";
	else
		return "Incorrect suit values, this shouldn't happen";
}









