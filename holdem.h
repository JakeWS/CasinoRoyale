#ifndef holdem_h
#define holdem_h

#include <vector>
#include "holdemPlayer.h"
#include "../Deck/Deck.h"

class holdem{
	private:
		std::vector<card> sharedHand;
		deckClass deck;
		unsigned short numPlayers;
	public:
		holdem(std::vector<holdemPlayer>&);
		//~holdem();
		void dealCards(std::vector<holdemPlayer>&);
		void printSharedHand(void);
		void flop(void);
		void turn(void);
		void river(void);
		void findWinner(std::vector<holdemPlayer>);
		void DEBUG_sharedHand(int[]);
		void DEBUG_dealCards(int[], std::vector<holdemPlayer>&);
		void DEBUG_FILE_dealCards(int[], std::vector<holdemPlayer>&);
		std::vector<card> DEBUG_getSharedHand(void);
};
#endif