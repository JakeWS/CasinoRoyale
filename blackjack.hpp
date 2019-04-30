#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

class BlackJack
{
  private:

  public:
    BlackJack();         // Blackjack constructor
    ~BlackJack();        // Blackjack destructor
    bool userChoice;     // Hit or stay (?)
    short cardTotal;     // stored value of the hand
    card userHand;       // Users cards (2 cards to start) [should be able to hold an infinite amount of cards]
    card discardPile;    // Discard pile
    card drawPile;       // Gives user 1 card when they hit
    card shuffleDeck;    // Shuffles deck
    card dealCards;      // Deals cards (2 cards per person [user/dealer])
    void countHand();    // count cardTotal for Blackjack
    void detWin();       // Uses cardTotal, checks if hand is == 21, then it's a winning hand
    void Hit();          // Hit means "give me more cards"
    void Stay();         // Stay means "i am done, give me no more cards"
};
#endif
