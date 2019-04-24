#ifndef Card_h
#define Card_h
#include <string>
class card{
	private:
		short cardValue; //2=2, 3=3, ... , J=11, Q=12, K=13, Ace=14
		short suit; //0=Heart, 1=Club, 2=Diamond, 3=Spade
	
	public:
		card();
		//~card();
		card(short, char);
		short getValue(void);
		std::string getSuit(void);
};
#endif