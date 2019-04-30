// Coded by Matthew J.

#include <iostream>
#include <algorithm>
#include "Deck.hpp"
#include "randGen.hpp"

using namespace std;

deckClass::deckClass()
{
	short cardValue = 0;
	for(int i = 0; i < 1*52/4; i++)
		this->deck.push_back(card((i) + 2, 'H'));
	for(int i = 1*52/4; i < 2*52/4; i++)
		this->deck.push_back(card((i-14*1) + 3, 'C'));
	for(int i = 2*52/4; i < 3*52/4; i++)
		this->deck.push_back(card((i-14*2) + 4, 'D'));
	for(int i = 3*52/4; i < 4*52/4; i++)
		this->deck.push_back(card((i-14*3) + 5, 'S'));
	
}

void deckClass::printDeck()
{	
	for(int i = 0; i < 52; i++){
		cout<<this->deck[i].getValue()<<this->deck[i].getSuit()[0]<<"  ";
		if (i == 12 || i == 25 || i == 38 || i == 51)
			cout<<endl;
	}
	cout<<endl;
}

void deckClass::shuffleDeck()
{
	random_shuffle(this->deck.begin(), this->deck.end(), randGen::randomIntGenerator);
}

card deckClass::popCard()
{
	card returnCard;
	returnCard = this->deck.back();
	this->deck.pop_back();
	return returnCard;
}
