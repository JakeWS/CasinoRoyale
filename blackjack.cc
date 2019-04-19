#include <iostream>
#include "Card.cc"
#include "Card.h"
#include "Deck.cc"
#include "Deck.h"

using namespace std;

class BlackJack
{
  private:

  public:
    BlackJack();        // Blackjack constructor
    ~BlackJack();       // Blackjack destructor
    bool userChoice;    // Hit or stay (?)
    short cardTotal;    // stored value of the hand
    card userHand;      // Users cards (2 cards to start) [should be able to hold an infinite amount of cards]
    card dealerHand;    // Dealers cards (2 cards) [should be able to hold an infinite amount of cards]
    card discardPile;   // Discard pile
    card drawPile;      // Gives user 1 card when they hit
    card shuffleDeck;   // Shuffles deck
    card dealCards;     // Deals cards (2 cards per person [user/dealer])
    void countHand();   // Sum of the two cards in userHand; uses/is sent to cardTotal
    void discardHand(); // When user decides to discard/'fold'(?)
    void detWin();      // Uses cardTotal, checks if hand is == 21, then it's a winning hand
    void Hit();         // Hit means "give me more cards"
    void Stay();        // Stay means "i am done, give me no more cards"
};

//Main Function
int main()
{
  BlackJack newBlackJack;
}

// BlackJack
BlackJack::BlackJack()
{
  bool continueLoop = true;
  int userChoice;
// mem alloc.
  while(continueLoop)
  {
     cout<<"What would you like to do?"<< endl<<"0. Exit Game."<< endl<<"1. Hit."<< endl<<"2. Stay."<< endl;
     cin>>userChoice;

    if(userChoice == 0)
    {
       cout<<"Exiting..."<< endl;
      continueLoop = false;

    //  make continueloop a method
    }
    else if(userChoice == 1)
    {
      Hit();
      countHand();
    }
    else if(userChoice == 2)
    {
      Stay();
      countHand();
    }
    else
    {
       cout<<"Unable to process, please respond to the prompt again."<< endl;
    }
  }
}

// ~BlackJack
// mem alloc.
BlackJack::~BlackJack()
{
   cout<<"Leaving the game."<< endl;
}

// Sum of cards in hand
void BlackJack::countHand()
{
  short cardTotal;
  card userHand;



}

// Player discards hand
void BlackJack::discardHand()
{
  card discardPile;
  // ??
  //incomplete
   cout<<"Discarding Hand."<< endl;
  // the cards go into the discard pile


}

// Determine a win (cardTotal == 21)
void BlackJack::detWin()
{
  // if cardTotal = 21 then yay u win
  short cardTotoal;

  if(cardTotal == 21) // if player has a winning hand (21)
  {
     cout<<"Congradulations!! You win!"<< endl;
     cout<<"What would you like to do now?"<< endl<<"0. Exit"<< endl<<"1. Play Again"<< endl;
     cin>>userChoice;

    if(userChoice == 0)
    {
       cout<<"Exiting..."<< endl;
    }
    else if(userChoice == 1)
    {
      BlackJack();  // starts a new game
    }
  }
  else if(cardTotal > 21) // if sum of cards is > 21
  {
     cout<<"Sorry, you lose!"<< endl;
     cout<<"What would you like to do now?"<< endl<<"0. Exit"<< endl<<"1. Play Again"<< endl;
     cin>>userChoice;

    if(userChoice == 0)
    {
       cout<<"Exiting..."<< endl;
    }
    else if(userChoice == 1)
    {
      BlackJack();  // starts a new game
    }
  }
}

// Hit function
void BlackJack::Hit()
{
  card userHand;
  card drawPile;
  card dealCards;
  //deals a card

}

// Stay function
void BlackJack::Stay()
{
  card userHand;
  short cardTotal;
  // doesnt deal a card
}
