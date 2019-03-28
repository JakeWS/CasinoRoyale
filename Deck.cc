#include <iostream>
#include <algorithm>
#include "Deck.h"
#include "randGen.h"

using namespace std;

deckClass::deckClass()
{
	short cardValue = 0;
	for(int i = 0; i < 52; i++){
		this->deck.push_back(card((i % 13) + 2, (short)(i/13))%4);
	}
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