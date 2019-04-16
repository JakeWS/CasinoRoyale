#include "holdem.h"
#include <iostream>
#include <string.h>
#include "holdemPlayer.h"
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
	std::vector<holdemPlayer> players;
	for (int i = 0; i < 2; i++) {
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
			int cardsToDeal[8];
			int sharedHandCards[10];
			while (getline(inputFile, line))
			{
				int i = 0;
				char * pch;
				//istringstream(line.substr(0, line.find(delimiter))) >> i;
				//cardsToDeal[0] = istringstream(line.substr(0, line.find(delimiter)));
				//const char * tempLineChar = line.c_str();
				char *lineChar = new char[line.length() + 1];
				strcpy(lineChar, line.c_str());
				pch = strtok(lineChar, " ");
				while (pch != NULL)
				{
					cout << pch << endl;
					pch = strtok(NULL, " ");
					cardsToDeal[i] = stoi(pch);
					i++;
				}
				//cardsToDeal[0] = istringstream(line.substr(0, line.find(delimiter)));
				//cout << i << endl;
				cout << line << endl;
			}
		}
		return 0;
	}
	else { //Standard mode
		game.dealCards(players);
		for (int i = 0; i < 2; i++)
		{
			cout << "Player # " << players[i].getID() << "'s hand: ";
			players[i].printHand();
		}
		game.flop();
		game.turn();
		game.river();
	}
	game.printSharedHand();
	game.findWinner(players);
/*
	//Write game output to file
	if (argc == 1)
	{
		char writeToFile;
		cout << "Write this game to file for examination? (y, n)";
		cin >> writeToFile;
		if (writeToFile == 'y' || writeToFile == 'Y')
		{
			ofstream savedGamesFile;
			savedGamesFile.open("savedGames.txt", ios::app);
			string notesOnGame;
			cout << "Notes: ";
			cin >> notesOnGame; //THIS DOESN'T READ SPACES, NEEDS TO BE FIXED
			savedGamesFile << "Notes: " << notesOnGame << "\n";
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

			//Write Code in file
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
			savedGamesFile << endl;
			savedGamesFile << endl;
			savedGamesFile.close();
		}
	}*/
}