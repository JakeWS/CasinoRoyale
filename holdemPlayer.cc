#include<iostream>
#include "holdemPlayer.h"

using namespace std;

holdemPlayer::holdemPlayer()
{
	for(int i = 0; i < 2; i++)
	{
		card pushCard;
		this->hand.push_back(pushCard);	
	}
	
}

void holdemPlayer::printHand()
{
	for(int i=0; i<2; i++)
		cout<<this->hand[i].getValue()<<this->hand[i].getSuit()[0]<<"  ";
	cout << endl;
}