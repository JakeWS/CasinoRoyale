#include <iostream>
#include <algorithm>
#include "holdem.h"
using namespace std;

holdem::holdem(vector<holdemPlayer> &players)
{
	deckClass tempDeck;
	this->deck = tempDeck;
	this->deck.shuffleDeck();
	//this->deck.printDeck();
	this->numPlayers = players.size();
}

void holdem::dealCards(vector<holdemPlayer> &players)
{
	for (int i = 0; i < this->numPlayers * 2; i++)
	{
		players[i % this->numPlayers].hand[i / this->numPlayers] = (this->deck).popCard();
	}
}

void holdem::DEBUG_dealCards(int newCardsVector[8], vector<holdemPlayer> &players)
{
	for (int i = 0; i < this->numPlayers*4; i += 2)
	{
		card newCard(newCardsVector[i], newCardsVector[i + 1]);
		players[(i/2)%this->numPlayers].hand[(i/2) / this->numPlayers] = newCard;
	}
}

void holdem::DEBUG_FILE_dealCards(int newCardsVector[2], vector<holdemPlayer> &players)
{
	for (int i = 0; i < this->numPlayers*4; i += 2)
	{
		card newCard(newCardsVector[i], newCardsVector[i + 1]);
		players[(i/2)%this->numPlayers].hand[(i/2) / this->numPlayers] = newCard;
	}
}

void holdem::DEBUG_sharedHand(int newCardsVector[10])
{
	for (int i = 0; i < 10; i += 2)
	{
		card tempCard(newCardsVector[i], newCardsVector[i + 1]);
		this->sharedHand.push_back(tempCard);
	}
}

vector<card> holdem::DEBUG_getSharedHand() 
{
	vector<card> returnThis;
	for (int i = 0; i < 5; i++)
	{
		returnThis.push_back(this->sharedHand[i]);
	}
	return returnThis;
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
	card burnCard = this->deck.popCard();
	this->sharedHand.push_back(this->deck.popCard());
	this->sharedHand.push_back(this->deck.popCard());
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::turn()
{
	card burnCard = this->deck.popCard();
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::river()
{
	card burnCard = this->deck.popCard();
	this->sharedHand.push_back(this->deck.popCard());
}

void holdem::findWinner(vector<holdemPlayer> players)
{
		
	holdemPlayer currentWinner;
	unsigned short winningHand = 0;

	//Check High Card (0)
	if(1)
	{
		unsigned short highestValue = 0;
		for(int i = 0; i < this->numPlayers; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				if(players[i].hand[j].getValue() > highestValue)
				{
					highestValue = players[i].hand[j].getValue();
					currentWinner = players[i];
					winningHand = 0;
				}
			}
		}
	}
	//Check One Pair (1)
	if(1)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			//One pair in hand
			if (players[playerIt].hand[0].getValue() == players[playerIt].hand[1].getValue()
			 && players[playerIt].hand[0].getValue() > highestValue)
			{
				highestValue = players[playerIt].hand[0].getValue();
				currentWinner = players[playerIt];
				winningHand = 1;
			}
			
			for(int handCardIt = 0; handCardIt < 2; handCardIt++)
			{
				for(int sharedCardIt = 0; sharedCardIt < 5; sharedCardIt++)
				{
					//One card in hand, one card in pool
					if (players[playerIt].hand[handCardIt].getValue() == this->sharedHand[sharedCardIt].getValue()
					 && players[playerIt].hand[handCardIt].getValue() > highestValue)
					{
						highestValue = players[playerIt].hand[handCardIt].getValue();
						currentWinner = players[playerIt];
						winningHand = 1;
					}
				}
			}
		}
	}
	//Check Two Pair (2)
	if(1)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			for (int handCardIt = 0; handCardIt < 2; handCardIt++)
			{
				for (int sharedCardIt = 0; sharedCardIt < 5; sharedCardIt++)
				{
					//Pair in the hand, Pair in the pool
					if (players[playerIt].hand[0].getValue() == players[playerIt].hand[1].getValue()) //Pair in the hand
					{
						for (int poolCard = 0; poolCard < 3; poolCard++)
						{
							if (this->sharedHand[(sharedCardIt + 1) % 5].getValue() == this->sharedHand[(sharedCardIt + poolCard) % 5].getValue()//Pair in the pool
								&& players[playerIt].hand[handCardIt].getValue() > highestValue)
							{
								highestValue = this->sharedHand[sharedCardIt].getValue();
								currentWinner = players[playerIt];
								winningHand = 2;
							}
						}
					}

					//One card in hand paired with one in the pool, one pair in the pool
					//This will break if 2 players have the largest pair in their hands with the same value
					if (players[playerIt].hand[handCardIt].getValue() == this->sharedHand[sharedCardIt].getValue()
						&& players[playerIt].hand[handCardIt].getValue() > highestValue) //Pair with one card in hand, another in the pool
					{
						for (int poolCard = 0; poolCard < 3; poolCard++)
						{
							if (this->sharedHand[(sharedCardIt+1) % 5].getValue() == this->sharedHand[(sharedCardIt + poolCard) % 5].getValue())//Pair in the pool
							{
								highestValue = this->sharedHand[sharedCardIt].getValue();
								currentWinner = players[playerIt];
								winningHand = 2;
							}
						}
					}
				}
			}
		}
	}
	//Check Three of a Kind (3)
	if(1)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			for (int handCardIt = 0; handCardIt < 2; handCardIt++)
			{
				for (int sharedHandIt = 0; sharedHandIt < 5; sharedHandIt++)
				{
					//Pair in the hand, third card in pool
					if (players[playerIt].hand[0].getValue() == players[playerIt].hand[1].getValue() //Pair in the hand
						&& players[playerIt].hand[0].getValue() == this->sharedHand[sharedHandIt].getValue()//Pair in the pool
						&& players[playerIt].hand[handCardIt].getValue() > highestValue)
					{
						highestValue = players[playerIt].hand[handCardIt].getValue();
						currentWinner = players[playerIt];
						winningHand = 3;
					}
					//One card in hand, one pair in the pool
					vector<short> cardValues;
					//Grab 4 from the pool
					cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 3) % 5].getValue());
					//Grab the 1 from the hand
					short handCardValue;
					handCardValue = players[playerIt].hand[handCardIt].getValue();

					for (int i = 0; i < 3; i++)
					{
						for (int j = i + 1; j < 4; j++)
						{
							if (players[playerIt].hand[handCardIt].getValue() == cardValues[i]
								&& cardValues[i] == cardValues[j])
							{

								highestValue = this->sharedHand[sharedHandIt].getValue();
								currentWinner = players[playerIt];
								winningHand = 3;
							}
						}
					}
						
					
					//if (players[playerIt].hand[handCardIt].getValue() == this->sharedHand[sharedCardIt].getValue()) //Pair with one card in hand, another in the pool
					//{
						/*
						for (int poolCard = 0; poolCard < 3; poolCard++)
						{
							if (this->sharedHand[(sharedCardIt + 1) % 5].getValue() == this->sharedHand[(sharedCardIt + poolCard) % 5].getValue())//Pair in the pool
							{
								highestValue = this->sharedHand[sharedCardIt].getValue();
								currentWinner = players[playerIt];
								winningHand = 3;
								cout << "sharedCardIt: " << sharedCardIt << endl;
							}
						}*/
					//}
				}
			}
		}
	}
	//Check Straight (4)
	if(1)
	{
		unsigned short highestValue = 0;
		for (int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			//One card in hand, 4 others in pool
			for (int handIt = 0; handIt < 2; handIt++)
			{
				for (int sharedHandIt = 0; sharedHandIt < 5; sharedHandIt++)
				{
					vector<short> cardValues;
					//Grab 4 from the pool
					cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 3) % 5].getValue());
					//Grab the 1 from the hand
					cardValues.push_back(players[playerIt].hand[handIt].getValue());
					sort(cardValues.begin(), cardValues.end());

					if (cardValues[0] == cardValues[1] - 1
						&& cardValues[1] == cardValues[2] - 1
						&& cardValues[2] == cardValues[3] - 1
						&& cardValues[3] == cardValues[4] - 1
						&& players[playerIt].hand[handIt].getValue() > highestValue)
					{
						highestValue = players[playerIt].hand[handIt].getValue();
						currentWinner = players[playerIt];
						winningHand = 4;
					}
				}
			}
			//Two cards in hand, 3 others in pool
			for (int sharedHandIt = 0; sharedHandIt < 3; sharedHandIt++)
			{
				for (int poolIt = sharedHandIt + 1; poolIt < 4; poolIt++)
				{
					for (int k = poolIt + 1; k < 5; k++)
					{
						vector<short> cardValues;
						vector<short> handCardValues;
						//Grab 3 from the pool
						cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
						cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
						cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
						//Grab the 2 from the hand
						cardValues.push_back(players[playerIt].hand[0].getValue());
						cardValues.push_back(players[playerIt].hand[1].getValue());
						sort(cardValues.begin(), cardValues.end());

						handCardValues.push_back(players[playerIt].hand[0].getValue());
						handCardValues.push_back(players[playerIt].hand[1].getValue());

						if (cardValues[0] == cardValues[1] - 1
							&& cardValues[1] == cardValues[2] - 1
							&& cardValues[2] == cardValues[3] - 1
							&& cardValues[3] == cardValues[4] - 1
							&& *max_element(handCardValues.begin(), handCardValues.end()) > highestValue)
						{
							highestValue = *max_element(handCardValues.begin(), handCardValues.end());
							currentWinner = players[playerIt];
							winningHand = 4;
						}
					}
				}
			}
		}
	}
	//Check Flush (5)
	if(1)
	{
		unsigned short highestValue = 0;
		for (int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{

			vector<unsigned char> cardSuits;
			vector<short> cardValues;
			cardSuits.push_back(this->sharedHand[0].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[1].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[2].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[3].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[4].getSuit()[0]);

			cardValues.push_back(players[playerIt].hand[0].getValue());
			cardValues.push_back(players[playerIt].hand[1].getValue());

			//Check both hand cards together against 3 pool cards
			for (int i = 0; i < 3; i++)
			{
				for (int j = i+1; j < 4; j++)
				{
					for (int k = j+1; k < 5; k++)
					{
						if (players[playerIt].hand[0].getSuit()[0] == players[playerIt].hand[1].getSuit()[0]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[i]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[j]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[k]
							&& *max_element(cardValues.begin(), cardValues.end()) > highestValue)
						{
							highestValue = *max_element(cardValues.begin(), cardValues.end());
							currentWinner = players[playerIt];
							winningHand = 5;
						}
					}
				}
			}

			//Check both hand cards independently against 4 pool cards
			for (int handIt = 0; handIt < 2; handIt++)
			{
				short handCardValue = players[playerIt].hand[handIt].getValue();
				for (int i = 0; i < 5; i++)
				{
					if (players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 1) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 2) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 3) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 4) % 5]
						&& handCardValue > highestValue)
					{
						highestValue = handCardValue;
						currentWinner = players[playerIt];
						winningHand = 5;
					}
				}
			}
		}
	}
	//Check Full House (6)
	if(1)
	{
	
		unsigned short highestValue = 0;
		for (int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			//cout << "New Player" << endl;
			//One card in hand, 4 others in pool
			for (int handIt = 0; handIt < 2; handIt++)
			{
				for (int sharedHandIt = 0; sharedHandIt < 5; sharedHandIt++)
				{
					vector<char> cardSuits;
					//Grab 4 from the pool
					cardSuits.push_back(this->sharedHand[sharedHandIt].getSuit()[0]);
					cardSuits.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getSuit()[0]);
					cardSuits.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getSuit()[0]);
					cardSuits.push_back(this->sharedHand[(sharedHandIt + 3) % 5].getSuit()[0]);
					//Grab the 1 from the hand
					cardSuits.push_back(players[playerIt].hand[handIt].getSuit()[0]);
					short handCardValue;
					handCardValue = players[playerIt].hand[handIt].getValue();

					//Pairing card is 1 ahead of the "base card"
					for (int i = 0; i < 5; i++)
					{
						if (cardSuits[i] == cardSuits[(i + 1) % 5]) //Pair
						{
							if (cardSuits[(i + 2) % 5] == cardSuits[(i + 3) % 5]
								&& cardSuits[(i + 2) % 5] == cardSuits[(i + 4) % 5]
								&& handCardValue > highestValue) //3 of a kind
							{
								highestValue = handCardValue;
								currentWinner = players[playerIt];
								winningHand = 6;
								//cout << "Win Condition 1" << endl;
							}
						}
					}

					//Pairing card is 2 ahead of the "base card"
					for (int i = 0; i < 5; i++)
					{
						if (cardSuits[i] == cardSuits[(i + 2) % 5]) //Pair
						{
							if (cardSuits[(i + 1) % 5] == cardSuits[(i + 3) % 5]
								&& cardSuits[(i + 1) % 5] == cardSuits[(i + 4) % 5]
								&& handCardValue > highestValue) //3 of a kind
							{
								highestValue = handCardValue;
								currentWinner = players[playerIt];
								winningHand = 6;
								//cout << "Win Condition 2" << endl;
							}
						}
					}
				}
			}


			//Two cards in hand, 3 others in pool
			for (int sharedHandIt = 0; sharedHandIt < 3; sharedHandIt++)
			{
				for (int poolIt = sharedHandIt + 1; poolIt < 4; poolIt++)
				{
					for (int k = poolIt + 1; k < 5; k++)
					{
						vector<char> cardSuits;
						vector<short> cardValues;
						//Grab 3 from the pool
						cardSuits.push_back(this->sharedHand[sharedHandIt].getSuit()[0]);
						cardSuits.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getSuit()[0]);
						cardSuits.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getSuit()[0]);
						//Grab the 2 from the hand
						cardSuits.push_back(players[playerIt].hand[0].getSuit()[0]);
						cardSuits.push_back(players[playerIt].hand[1].getSuit()[0]);
						cardValues.push_back(players[playerIt].hand[0].getValue());
						cardValues.push_back(players[playerIt].hand[1].getValue());

						if (cardSuits[0] == cardSuits[1] - 1
							&& cardSuits[1] == cardSuits[2] - 1
							&& cardSuits[2] == cardSuits[3] - 1
							&& cardSuits[3] == cardSuits[4] - 1
							&& *max_element(cardValues.begin(), cardValues.end()) > highestValue)
						{
							highestValue = *max_element(cardValues.begin(), cardValues.end());
							currentWinner = players[playerIt];
							winningHand = 6;
							//cout << "Win Condition 3" << endl;
						}
					}
				}
			}

		}
	}
	//Check Four of a Kind (7)
	if(1)
	{
		unsigned short highestValue = 0;
		for(int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			for (int handCardIt = 0; handCardIt < 2; handCardIt++)
			{
				//Pair in the hand, pair card in pool
				if (players[playerIt].hand[0].getValue() == players[playerIt].hand[1].getValue() //Pair in the hand
				 && players[playerIt].hand[handCardIt].getValue() > highestValue)
				 {
					for (int sharedCardIt = 0; sharedCardIt < 4; sharedCardIt++)
					{
						for(int poolIt = sharedCardIt; poolIt < 5; poolIt++)
						{
							if(this->sharedHand[sharedCardIt].getValue() == this->sharedHand[poolIt].getValue()) //There is a pair in the pool
							{
								if(players[playerIt].hand[0].getValue() == this->sharedHand[sharedCardIt].getValue()) //If it is actually a Four of a Kind
								{	
									highestValue = this->sharedHand[sharedCardIt].getValue();
									currentWinner = players[playerIt];
									winningHand = 7;
								}
							}
						}
					}
				 }
				//One card in hand, three of a kind in the pool
				for (int sharedCardIt = 0; sharedCardIt < 5; sharedCardIt++)
				{
					if (players[playerIt].hand[handCardIt].getValue() == this->sharedHand[sharedCardIt].getValue()) //Pair with one card in hand, another in the pool
					{
						for (int i = sharedCardIt+1; i < 4; i++)
						{
							for (int j = i + 1; j < 5; j++)
							{
								if (this->sharedHand[i].getValue() == this->sharedHand[j].getValue()) //Another Pair the pool
								{
									if (this->sharedHand[i].getValue() == players[playerIt].hand[handCardIt].getValue()
										&& this->sharedHand[i].getValue() > highestValue)
									{
										highestValue = this->sharedHand[i].getValue();
										currentWinner = players[playerIt];
										winningHand = 7;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//Check Straight Flush (8)
	if(1)
	{
		unsigned short highestValue = 0;
		for (int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{

			vector<unsigned char> cardSuits;
			vector<short> handCardValues;
			cardSuits.push_back(this->sharedHand[0].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[1].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[2].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[3].getSuit()[0]);
			cardSuits.push_back(this->sharedHand[4].getSuit()[0]);

			handCardValues.push_back(players[playerIt].hand[0].getValue());
			handCardValues.push_back(players[playerIt].hand[1].getValue());

			//Check both hand cards together against 3 pool cards
			for (int i = 0; i < 3; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					for (int k = j + 1; k < 5; k++)
					{
						if (players[playerIt].hand[0].getSuit()[0] == players[playerIt].hand[1].getSuit()[0]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[i]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[j]
							&& players[playerIt].hand[0].getSuit()[0] == cardSuits[k]
							&& *max_element(handCardValues.begin(), handCardValues.end()) > highestValue)
						{
							//There is a flush
							for (int sharedHandIt = 0; sharedHandIt < 3; sharedHandIt++)
							{
								for (int poolIt = sharedHandIt + 1; poolIt < 4; poolIt++)
								{
									for (int k = poolIt + 1; k < 5; k++)
									{
										vector<short> cardValues;
										vector<short> handCardValues;
										//Grab 3 from the pool
										cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
										cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
										cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
										//Grab the 2 from the hand
										cardValues.push_back(players[playerIt].hand[0].getValue());
										cardValues.push_back(players[playerIt].hand[1].getValue());
										sort(cardValues.begin(), cardValues.end());

										if (cardValues[0] == cardValues[1] - 1
											&& cardValues[1] == cardValues[2] - 1
											&& cardValues[2] == cardValues[3] - 1
											&& cardValues[3] == cardValues[4] - 1
											&& *max_element(handCardValues.begin(), handCardValues.end()) > highestValue)
										{
											//There is a straight flush
											highestValue = *max_element(handCardValues.begin(), handCardValues.end());
											currentWinner = players[playerIt];
											winningHand = 8;
										}
									}
								}
							}
						}
					}
				}
			}

			//Check both hand cards independently against 4 pool cards
			for (int handIt = 0; handIt < 2; handIt++)
			{
				for (int i = 0; i < 5; i++)
				{
					if (players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 1) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 2) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 3) % 5]
						&& players[playerIt].hand[handIt].getSuit()[0] == cardSuits[(i + 4) % 5]
						&& handCardValues[handIt] > highestValue)
					{
						//There is a flush
						for (int sharedHandIt = 0; sharedHandIt < 5; sharedHandIt++)
						{
							vector<short> cardValues;
							//Grab 4 from the pool
							cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
							cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
							cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
							cardValues.push_back(this->sharedHand[(sharedHandIt + 3) % 5].getValue());
							//Grab the 1 from the hand
							cardValues.push_back(players[playerIt].hand[handIt].getValue());
							sort(cardValues.begin(), cardValues.end());

							if (cardValues[0] == cardValues[1] - 1
								&& cardValues[1] == cardValues[2] - 1
								&& cardValues[2] == cardValues[3] - 1
								&& cardValues[3] == cardValues[4] - 1
								&& handCardValues[handIt] > highestValue)
							{
								//There is a straight flush
								highestValue = cardValues.back();
								currentWinner = players[playerIt];
								winningHand = 8;
							}
						}
					
					}
				}
			}
		}
	}
	//Check Royal Flush (9)
	if (1)
	{
		unsigned short highestValue = 0;
		for (int playerIt = 0; playerIt < this->numPlayers; playerIt++)
		{
			//One card in hand, 4 others in pool
			for (int handIt = 0; handIt < 2; handIt++)
			{
				for (int sharedHandIt = 0; sharedHandIt < 5; sharedHandIt++)
				{
					vector<short> cardValues;
					//Grab 4 from the pool
					cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
					cardValues.push_back(this->sharedHand[(sharedHandIt + 3) % 5].getValue());
					//Grab the 1 from the hand
					cardValues.push_back(players[playerIt].hand[handIt].getValue());
					sort(cardValues.begin(), cardValues.end());

					if (cardValues[0] == cardValues[1] - 1
						&& cardValues[1] == cardValues[2] - 1
						&& cardValues[2] == cardValues[3] - 1
						&& cardValues[3] == cardValues[4] - 1
						&& players[playerIt].hand[handIt].getValue() > highestValue
						&& cardValues.back() == 14)
					{
						highestValue = players[playerIt].hand[handIt].getValue();
						currentWinner = players[playerIt];
						winningHand = 9;
					}
				}
			}
			//Two cards in hand, 3 others in pool
			for (int sharedHandIt = 0; sharedHandIt < 3; sharedHandIt++)
			{
				for (int poolIt = sharedHandIt + 1; poolIt < 4; poolIt++)
				{
					for (int k = poolIt + 1; k < 5; k++)
					{
						vector<short> cardValues;
						vector<short> handCardValues;
						//Grab 3 from the pool
						cardValues.push_back(this->sharedHand[sharedHandIt].getValue());
						cardValues.push_back(this->sharedHand[(sharedHandIt + 1) % 5].getValue());
						cardValues.push_back(this->sharedHand[(sharedHandIt + 2) % 5].getValue());
						//Grab the 2 from the hand
						cardValues.push_back(players[playerIt].hand[0].getValue());
						cardValues.push_back(players[playerIt].hand[1].getValue());
						sort(cardValues.begin(), cardValues.end());

						handCardValues.push_back(players[playerIt].hand[0].getValue());
						handCardValues.push_back(players[playerIt].hand[1].getValue());

						if (cardValues[0] == cardValues[1] - 1
							&& cardValues[1] == cardValues[2] - 1
							&& cardValues[2] == cardValues[3] - 1
							&& cardValues[3] == cardValues[4] - 1
							&& *max_element(handCardValues.begin(), handCardValues.end()) > highestValue
							&& cardValues.back() == 14)
						{
							highestValue = *max_element(handCardValues.begin(), handCardValues.end());
							currentWinner = players[playerIt];
							winningHand = 9;
						}
					}
				}
			}
		}
	}

	cout << "Winning player: " << currentWinner.getID() << " with a ";
	switch (winningHand) {
	case 0: cout << "High Card"; break;
	case 1: cout << "One Pair"; break;
	case 2: cout << "Two Pair"; break;
	case 3: cout << "Three of a Kind"; break;
	case 4: cout << "Straight"; break;
	case 5: cout << "Flush"; break;
	case 6: cout << "Full House"; break;
	case 7: cout << "Four of a Kind"; break;
	case 8: cout << "Straight Flush"; break;
	case 9: cout << "Royal Flush"; break;
	}
	cout << endl;
	
}



