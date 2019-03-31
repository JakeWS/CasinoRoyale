#include <iostream>
#include "holdem.h"
using namespace std;

holdem::holdem()
{
	deckClass tempDeck;
	this->deck = tempDeck;
	this->deck.shuffleDeck();
	for (int i=0; i < (this->numPlayers); i++)
	{
		holdemPlayer tempPlayer;
		(this->players).push_back(tempPlayer);
	}
	this->deck.printDeck();
}

void holdem::dealCards()
{
	for (int i=0; i < this->numPlayers*2; i++)
	{
		this->players[i%numPlayers].hand[i/numPlayers] = (this->deck).popCard();
	}
	for(int i=0; i < (this->numPlayers); i++)
		this->players[i].printHand();
}

void holdem::printSharedHand()
{
	for(int i = 0; i < this->sharedHand.size(); i++)
	{
		cout<<this->sharedHand[i].getValue()<<this->sharedHand[i].getSuit()[0]<<"   ";
	}
	cout<<endl;
}

void holdem::flop()
{
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::turn()
{
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::river()
{
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::findWinner()
{
	/*struct bestHand
	{
		unsigned short handValue;
		unsigned short handHolder;
	}
	*/
	
	holdemPlayer currentWinner;
	if(1)//Check High Card (0)
	{
		unsigned short highestValue = 0;
		for(int i = 0; i < this->numPlayers; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				if(this->players[i].hand[j].getValue() > highestValue)
				{
					highestValue = this->players[i].hand[j].getValue();
					currentWinner = this->players[i];
				}
			}
		}
	}

	if(1)//Check One Pair (1)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			if (this->players[playerIt].hand[0].getValue() == this->players[playerIt].hand[1].getValue() && this->players[playerIt].hand[0].getValue() > highestValue)
			{
				highestValue = this->players[playerIt].hand[0].getValue();
				currentWinner = this->players[playerIt];
			}
			
			for(int handCardIt = 0; handCardIt < 2; handCardIt++)
			{
				for(int sharedCardIt = 0; sharedCardIt < 3; sharedCardIt++)
				{
					if (this->players[playerIt].hand[handCardIt].getValue() == this->sharedHand[sharedCardIt].getValue() && this->players[playerIt].hand[handCardIt].getValue() > highestValue)
					{
						highestValue = this->players[playerIt].hand[handCardIt].getValue();
						currentWinner = this->players[playerIt];
					}
				}
			}
		}
	}
	
	if(1)//Check Two Pair (2)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			//if ()
		}
	}
		/*
	if();//Check Three of a Kind (3)
	if();//Check Straight (4)
	if();//Check Flush (5)
	if();//Check Full House (6)
	if();//Check Four of a Kind (7)
	if();//Check Straight Flush (8)
	if();//Check Royal Flush (9)
		*/
	
	
	
}



