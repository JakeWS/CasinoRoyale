#include <iostream>
#include <cardFunctions.h>

using namesapce.std;

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

int main()
{
  BlackJack newBlackJack();
}

// BlackJack
BlackJack::BlackJack()
{
  bool continueLoop = true;
  bool userChoice;
  
  while(continueLoop)
  {
    cout<<"What would you like to do?"<<endl<<"0. Exit Game."<<endl<<"1. Hit."<<endl<<"2. Stay."<<endl;
    cin>>userChoice;
    
    if(userChoice == 0)
    {
      cout<<"Exiting"<<endl;
      continueLoop = 0;
    }
    else if(userChoice == 1)
    {
      
    }
    else if(userChoice == 2)
    {
      
    }
    else
    {
      cout<<"Unable to process, please respond to the prompt again."<<endl;
    }      
  }
}

// ~BlackJack
BlackJack::~BlackJack()
{
  cout<<"Leaving the game."<<endl;
}

// Sum of cards in hand
void BlackJack::countHand()
{
  short cardTotal;
  
  
}

// Player discards hand
void BlackJack::discardHand()
{
  // idk???? 
  // if the user knows they r gonna lose, then i guess the deconstructor?
  cout<<"Discarding Hand."<<endl;
  
}

// Determine a win (cardTotal == 21)
void BlackJack::detWin()
{
  // if cardTotal = 21 then yay u win
}

// Hit function
void BlackJack::Hit()
{
  //deals a card 
}

// Stay function
void BlackJack::Stay()
{
  // doesnt deal a card
}


