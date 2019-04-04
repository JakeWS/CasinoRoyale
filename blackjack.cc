#include <iostream>
#include <Card.cc>
#include <Card.h>
#include <cardFunctions.h>
#include <Deck.cc>
#include <Deck.h>
#include <CardTest.cc>

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
  BlackJack newBlackJack();
}

// BlackJack
BlackJack::BlackJack()
{
  bool continueLoop = true;
  int userChoice;

  while(continueLoop)
  {
    std::cout<<"What would you like to do?"<<std::endl<<"0. Exit Game."<<std::endl<<"1. Hit."<<std::endl<<"2. Stay."<<std::endl;
    std::cin>>userChoice;

    if(userChoice == 0)
    {
      std::cout<<"Exiting..."<<std::endl;
      continueLoop = 0;
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
      std::cout<<"Unable to process, please respond to the prompt again."<<std::endl;
    }
  }
}

// ~BlackJack
BlackJack::~BlackJack()
{
  std::cout<<"Leaving the game."<<std::endl;
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
  std::cout<<"Discarding Hand."<<std::endl;
  // the cards go into the discard pile


}

// Determine a win (cardTotal == 21)
void BlackJack::detWin()
{
  // if cardTotal = 21 then yay u win
  short cardTotoal;

  if(cardTotal == 21) // if player has a winning hand (21)
  {
    std::std::cout<<"Congradulations!! You win!"<<std::std::endl;
    std::cout<<"What would you like to do now?"<<std::endl<<"0. Exit"<<std::endl<<"1. Play Again"<<std::endl;
    std::std::cin>>userChoice;

    if(userChoice == 0)
    {
      std::cout<<"Exiting..."<<std::endl;
    }
    else if(userChoice == 1)
    {
      BlackJack();  // starts a new game
    }
  }
  else if(cardTotal > 21) // if sum of cards is > 21
  {
    std::cout<<"Sorry, you lose!"<<std::endl;
    std::cout<<"What would you like to do now?"<<std::endl<<"0. Exit"<<std::endl<<"1. Play Again"<<std::endl;
    std::cin>>userChoice;

    if(userChoice == 0)
    {
      std::cout<<"Exiting..."<<std::endl;
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
