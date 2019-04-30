// Blackjack library module
//
#include <iostream>
#include "Card.cc"
#include "Card.hpp"
#include "Deck.cc"
#include "Deck.hpp"
#include "blackjack.hpp"

using namespace std;

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

  do{
    countHand();
    cout<<"You have: "<<cardTotal<<"What would you like to do now?"<<"1. Hit."<<endl<<"2. Stay."<< endl;

  }while(userChoice == 1);

}

// Stay function
void BlackJack::Stay()  //If user stays, they will be dealt no cards and it will state their card total.
{
  //card userHand;
  short cardTotal;

  if(cardTotal > 21)  // If card total is greater than 21, the player busts
  {
    cout<<"BUST! You have: "<<cardTotal<<endl;
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
  else  // If card total is less than 21, just print out amount
  {
    cout<<"You have: "<<cardTotal<<endl;
  }
}

/*count cardTotal for Blackjack, cards is your array of cards, and n is the number of cards in your hand*/
int countHand(char cards[10][2], int n)
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
