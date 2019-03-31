#ifndef holdem_h
#define holdem_h

#include <vector>
#include "holdemPlayer.h"
#include "../Deck/Deck.h"

class holdem{
	private:
		std::vector<holdemPlayer> players;
		std::vector<card> sharedHand;
		deckClass deck;
		unsigned short numPlayers = 2;
	public:
		holdem();
		//~holdem();
		void dealCards(void);
		void printSharedHand(void);
		void flop(void);
		void turn(void);
		void river(void);
		void findWinner(void);
	
};
#endif