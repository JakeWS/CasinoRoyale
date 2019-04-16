#include<iostream>
#include "holdemPlayer.h"

using namespace std;

unsigned int holdemPlayer::nextID = 1;

holdemPlayer::holdemPlayer()
{
	for(int i = 0; i < 2; i++)
	{
		card pushCard;
		this->hand.push_back(pushCard);	
	}
	this->ID = nextID++;
}

void holdemPlayer::printHand()
{
	for(int i=0; i<2; i++)
		cout<<this->hand[i].getValue()<<this->hand[i].getSuit()[0]<<"  ";
	cout << endl;
}

unsigned int holdemPlayer::getID()
{
	return this->ID;
}