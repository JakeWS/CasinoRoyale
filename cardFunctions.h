/*Program functions makes cards, shuffles cards,
and puts them in a stack                            


/********************#include DIRECTIVES***********************************************/
#include <stdio.h>
#include <stdlib.h>                                         /*Needed for use of malloc*/
#include <time.h>                                           /*Enables time*/
/*************************************************************************************/
/********************Global Structure*************************************************/

typedef struct cardStack        /*A global structure used for each stack of cards/hand                      */
{                             
  char suit;                    /*Character of the node                                                     */
  char value;                   /*Integer to represent the frequency of the node                            */
  struct card* nextCard;        /*Pointer to next card in a stack                                           */
} CARD;

/*************************************************************************************/
/*Make cards*/
CARD* makeCards()
{
    char cardSuits[4] = {'d','c','h','s'};
    char cardValues[12] = {'2','3','4','5','6','7','8','9','J','Q','K','A'};
    int numDecks;
    int cardSuitCount = 0;
    int cardValueCount = 0;
    int deckIndex = 0;
    int cardIndex = 0;
    srand(time(0));
    /*Creation of cards*/
    numDecks = (rand() % 8 + 1); //Random number of decks, beteen 1 and 8 will be chosen
    CARD* cards[numDecks*52]; //Makes an array big enough to hold al cards
    CARD* tempCard = NULL; //Makes first card to be inserted into array
    for(; deckIndex < numDecks; deckIndex++) //Loops through all cards in the deck
    {
        printf("%li", sizeof(cardSuits)/sizeof(char));
        for(; cardSuitCount < sizeof(cardSuits)/sizeof(char); cardSuitCount++) //Loops through card suits
        {
            
            for(; cardValueCount < sizeof(cardValues)/sizeof(char); cardValueCount++) //Loops through card values
            {
                    tempCard = malloc(sizeof(CARD));        //Creates place in memory for new card
                    tempCard->suit = cardSuits[cardSuitCount]; //Sets new card's suit
                    tempCard->value = cardValues[cardValueCount]; //Sets new card's value
                    cards[cardIndex] = tempCard;        //Sets current spot in array to card
                    cardIndex++;                        //Increments to next array position
            }
        }
        if (cardSuitCount >= sizeof(cardSuitCount)/sizeof(char) && deckIndex < numDecks)
        {
            cardSuitCount = 0;
        }
        if (cardValueCount >= sizeof(cardValueCount)/sizeof(char) && deckIndex < numDecks)
        {
            cardValueCount = 0;
        }
    }
    return cards;
}

CARD* shuffleDeck(CARD* cards)
{
    srand(time(0));
    int index = 0;
    int shuffleInt = (rand() % 10000 + 1000);
    int randoInt1;
    int randoInt2;
    CARD* cardArray = cards;
    CARD* tempCard;

    for(;index < shuffleInt; index++)
    {
        randoInt1 = rand() % 52;
        randoInt2 = rand() % 52;
        if (randoInt1 == randoInt2)
        {
            randoInt2 = rand() % 52;
        }
        tempCard = &cards[randoInt1];
        cards[randoInt1] = cards[randoInt2];
        cards[randoInt2] = *tempCard;
    }
    return cards;
}

CARD* stackDeck(CARD* cards)
{
    int index = 0;
    CARD* topOfStack;
    CARD* tempCard;
    for (; index < sizeof(cards)/sizeof(char); index++)
    {
        if(topOfStack == NULL)
        {
            topOfStack = &cards[index];
            tempCard = &cards[index];
        }
        else
        {
            tempCard->nextCard = &cards[index];
            tempCard = &cards[index];
        } 
    }
    return topOfStack;
}