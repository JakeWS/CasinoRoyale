#ifndef Deck_h
#define Deck_h
#include <vector>
#include "Card.h"

class deckClass{
	private:
		std::vector<card> deck;
	public:
		deckClass();
		void shuffleDeck(void);
		void printDeck(void);
		card popCard(void);
};

#endif