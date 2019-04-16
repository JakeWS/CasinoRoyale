#ifndef holdemPlayer_h
#define holdemPlayer_h
#include "../Deck/Card.h"
#include <vector>
class holdemPlayer{
	private:
		int money;
		unsigned int ID;
		static unsigned int nextID;
	public: 
		std::vector<card> hand; //This shouldn't be public for security reasons
		void printHand(void);
		holdemPlayer();
		unsigned int getID(void);
	
};
#endif