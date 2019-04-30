#include "Deck.h"
#include <iostream>
using namespace std;

int main()
{
	deckClass newDeck;
	card testCard;
	
	newDeck.printDeck();
	newDeck.shuffleDeck();
	newDeck.printDeck();
	/*
	testCard = newDeck.popCard();
	cout<<testCard.getSuit()<<endl;
	cout<<testCard.getValue()<<endl;
	*/
	
}
