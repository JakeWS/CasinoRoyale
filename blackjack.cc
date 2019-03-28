#include <iostream>
#include <cardFunctions.h>

using namesapce.std;

class blackjackTable
{
  private:
  public:
    blackjackTable();   // Blackjack constructor
    ~blackjackTable();  // Blackjack destructor
    short userChoice;   // Hit or stay (?)
    short cardTotal;    // Gives the sum of the hand 
    card userHand;      // Users cards (1 card)
    card dealerHand;    // Dealers cards (1 card)
    card discardPile;   // Discard pile
    card drawPile;      // Gives user 1 card when they hit
    card shuffleDeck;   // Shuffles deck
    card dealCards;     // Deals cards (2 cards per person [user/dealer])
    void countHand();   // Sum of the two cards in userHand; uses/is sent to cardTotal
    void discardHand(); // When user decides to discard/'fold'(?)
    void detWin();      // Uses cardTotal, checks if hand is == 21, then it's a winning hand
};

int main()
{
  blackjackTable newblackjack();
}
