#include <iostream>
#include "Card.h"

using namespace std;

card::card()
{
	//cout<<"Constructing card"<<endl;
	this->cardValue = 1;
	this->suit = 1;
}

card::card(short setValue, char setSuit)
{
	//cout<<"Constructing card"<<endl;
	this->cardValue = setValue;
	switch (setSuit)
	{
		case 'h': this->suit = 0; break;
		case 'H': this->suit = 0; break;
		case 'c': this->suit = 1; break;
		case 'C': this->suit = 1; break;
		case 'd': this->suit = 2; break;
		case 'D': this->suit = 2; break;
		case 's': this->suit = 3; break;
		case 'S': this->suit = 3; break;
	}
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









