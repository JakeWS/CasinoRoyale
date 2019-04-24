#include "holdem.h"
#include <iostream>
#include <string.h>
#include "holdemPlayer.h"
#include <sstream>
#include <fstream>
#include <assert.h>
using namespace std;

int main(int argc, char* argv[]){
	std::vector<holdemPlayer> players;
	for (int i = 0; i < 1; i++) {
		holdemPlayer tempPlayer;
		players.push_back(tempPlayer);
	}
	holdem game(players);
	if (argc == 2) //Debug mode
	{
		int cardsToDeal[8] = { 4,'s',11,'s',6,'h',14,'s' };
		game.DEBUG_dealCards(cardsToDeal, players);
		int sharedHandCards[10] = { 7, 'h', 8, 'h', 10, 'd', 13, 'd', 13, 's' };
		game.DEBUG_sharedHand(sharedHandCards);
	}
	if (argc == 3) //Read Input From File
	{
		ifstream inputFile("testGames.txt");
		string line;
		if (inputFile.is_open())
		{
			int cardsToDeal[4];
			int sharedHandCards[10];
			int i = 0;
			while (getline(inputFile, line)) // Loop to get a new line
			{
				if ((line[0] == '/' && line[1] == '/')
				  || line[0] == '\r')
					continue;
				char *pch;
				char *lineChar = new char[line.length() + 1];
				strcpy(lineChar, line.c_str());
				pch = strtok(lineChar, " ");
				while (pch != NULL) //While you're not at the end of the current line
				{
					int expectedWinCondition;
					//Hand Cards
					if (i < 4)
					{
						//cout << "Hand Cards" << endl;
						if (i % 2 == 0) //Read a card value
						{
							cardsToDeal[i] = atoi(pch);
						}
						else //Read a card suit
						{
							cardsToDeal[i] = *pch;
						}
						//cout << cardsToDeal[i] << endl;
					}
					//Shared Cards
					if (i >= 4 && i <= 13)
					{
						//cout << "Pool Cards" << endl;
						if (i % 2 == 0)
						{
							sharedHandCards[i - 4] = atoi(pch);
						}
						else
						{
							sharedHandCards[i - 4] = *pch;
						}
						//cout << sharedHandCards[i-4] << endl;
					}
					if (i == 14)
						expectedWinCondition = atoi(pch);
					pch = strtok(NULL, " ");
					i++;
					if (i == 15) //All cards have been read for that game
					{
						int winCondition;
						game.DEBUG_FILE_dealCards(cardsToDeal, players);
						game.DEBUG_sharedHand(sharedHandCards);
						for (int i = 0; i < 1; i++)
						{
							cout << "Player # " << players[i].getID() << "'s hand: ";
							players[i].printHand();
						}
						game.printSharedHand();
						winCondition = game.findWinner(players);
						if (winCondition != expectedWinCondition)
						{
							cout << "Failure: win condition should be " << expectedWinCondition << ". Is " << winCondition;
						}
						cout << endl;
						assert(winCondition == expectedWinCondition);
						i = 0;
					}
				}
				//cout << line << endl;
			}
		}
		return 0;
	}
	else { //Standard mode
		game.dealCards(players);
		game.flop();
		game.turn();
		game.river();
	}
		for (int i = 0; i < 2; i++)
		{
			cout << "Player # " << players[i].getID() << "'s hand: ";
			players[i].printHand();
		}
	game.printSharedHand();
	game.findWinner(players);

	//Write game output to file
	if (argc == 1)
	{
		char writeToFile;
		cout << "Write this game to file for examination? (y, n)";
		cin >> writeToFile;
		if (writeToFile == 'y' || writeToFile == 'Y')
		{
			ofstream savedGamesFile;
			ofstream gamesToTestFile;
			savedGamesFile.open("savedGames.txt", ios::app);
			gamesToTestFile.open("regTestGames.txt", ios::app);
			/*string notesOnGame;
			cout << "Notes: ";
			cin >> notesOnGame; //THIS DOESN'T READ SPACES, NEEDS TO BE FIXED
			savedGamesFile << "Notes: " << notesOnGame << "\n";
			*/
			//Write As Readable
			for (int i = 0; i < 2; i++)
			{
				savedGamesFile << "Player # " << i + 1 << "'s hand: ";
				for (int j = 0; j < 2; j++)
				{
					savedGamesFile << players[i].hand[j].getValue() << players[i].hand[j].getSuit()[0] << " ";
				}
				savedGamesFile << endl;
			}
			for (int i = 0; i < 5; i++)
			{
				savedGamesFile << game.DEBUG_getSharedHand()[i].getValue() << game.DEBUG_getSharedHand()[i].getSuit()[0] << " ";
			}
			
			//Write to regression test file
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					gamesToTestFile << players[i].hand[j].getValue() << " " << players[i].hand[j].getSuit()[0] << " ";
				}
				gamesToTestFile << endl;
			}
			for (int i = 0; i < 5; i++)
			{
				gamesToTestFile << game.DEBUG_getSharedHand()[i].getValue() << " " << game.DEBUG_getSharedHand()[i].getSuit()[0] << " ";
			}

			/*//Write Code in file
			savedGamesFile << "\nint cardsToDeal[8] = {";
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					savedGamesFile << players[j].hand[i].getValue() << players[j].hand[i].getSuit()[0];
					savedGamesFile << ",";
				}
			}
			savedGamesFile << "}\n";
			savedGamesFile << "game.DEBUG_dealCards(cardsToDeal)";
			savedGamesFile << "int sharedHandCards[10] = { ";
			for (int i = 0; i < 5; i++)
			{
				savedGamesFile << game.DEBUG_getSharedHand()[i].getValue() << game.DEBUG_getSharedHand()[i].getSuit()[0];
				if (i != 4)
					savedGamesFile << ",";
				else
					savedGamesFile << "}\n";
			}
			savedGamesFile << "game.DEBUG_sharedHand(sharedHandCards)";
			*/
			savedGamesFile << endl;
			savedGamesFile << endl;
			gamesToTestFile << endl;
			gamesToTestFile << endl;
			savedGamesFile.close();
			gamesToTestFile.close();
		}
	}
}