#include "holdem.h"

int main(){
	holdem game;
	game.dealCards();
	game.flop();
	game.printSharedHand();
	game.turn();
	game.printSharedHand();
	game.river();
	game.printSharedHand();
}