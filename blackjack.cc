#include <iostream>
#include "Card.cc"
#include "Card.h"
#include "Deck.cc"
#include "Deck.h"

using namespace std;

int countcardTotal(char[10][2], int);

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
  short cardTotal;

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
  //card userHand;
  short cardTotal;

  if(cardTotal > 21)
  {
    cout<<"BUST! You have: "<<cardT
      otal<<endl;
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

/*count cardTotal for Blackjack, cards is your array of cards, and n is the number of cards in your hand*/
int countCardTotal(char cards[10][2], int n)
{
  int cardTotal = 0;
  for (int i=0; i<=n; i++)
  {
    if(cards[i][0] == 'T')
    {
      cardTotal += 10;
    }
    else if(cards[i][0] == 'J')
    {
      cardTotal += 10;
    }
    else if(cards[i][0] == 'Q')
    {
      cardTotal += 10;
    }
    else if(cards[i][0] == 'K')
    {
      cardTotal += 10;
    }
    else if(cards[i][0] == 'A')
    {
      if(cardTotal+11 > 21)
        cardTotal += 1;
      else
        cardTotal += 11;
    }
    else if(cards[i][0] == '2')
    {
      cardTotal += 2;
    }
    else if(cards[i][0] == '3')
    {
      cardTotal += 3;
    }
    else if(cards[i][0] == '4')
    {
      cardTotal += 4;
    }
    else if(cards[i][0] == '5')
    {
      cardTotal += 5;
    }
    else if(cards[i][0] == '6')
    {
      cardTotal += 6;
    }
    else if(cards[i][0] == '7')
    {
      cardTotal += 7;
    }
    else if(cards[i][0] == '8')
    {
      cardTotal += 8;
    }
    else if(cards[i][0] == '9')
    {
      cardTotal += 9;
    }
  }
  return cardTotal;
}
