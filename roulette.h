#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class RouletteTable {
private:
	short randomSpin;
	vector<short> rouletteChoice;
	vector<short> rouletteOdds;
public:
	RouletteTable();
	~RouletteTable();
	void displayTable();
	void spinWheel();
	void determineWin();
	void takeBets();
};

RouletteTable::RouletteTable()
{
	displayTable();
	takeBets();
}

RouletteTable::~RouletteTable()
{
	cout << "Table destroyed." << endl;
}

void RouletteTable::displayTable()
{

	for (int idx = 0; idx < 36; idx++)
	{
		cout << idx + 1;
		if (idx + 1 == 2 || idx + 1 == 4 || idx + 1 == 6 || idx + 1 == 8 || idx + 1 == 10 || idx + 1 == 11 || idx + 1 == 13
			|| idx + 1 == 15 || idx + 1 == 17 || idx + 1 == 20 || idx + 1 == 22 || idx + 1 == 24 || idx + 1 == 26 || idx + 1 == 28
			|| idx + 1 == 29 || idx + 1 == 31 || idx + 1 == 33 || idx + 1 == 35)
		{
			cout << "B ";
		}
		else
		{
			cout << "R ";
		}
		if ((idx + 4) % 3 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void RouletteTable::takeBets()
{
	int userChoice = -1;
	cout << "What would you like to bet on:" << endl << "0.Spin Wheel" << endl << "1-36. Individual Numbers"
		<< endl << "37. All Odds" << endl << "38. All Even" << endl << "39. All Black " << endl << "40. All Red" << endl
		<< "41. Column 1" << endl << "42. Column 2" << endl << "43. Column 3" << endl << "44. Row 1" << endl << "45. Row 2"
		<< endl << "46. Row 3" << endl << "47. Row 4" << endl << "48. Row 5" << endl << "49. Row 6" << endl << "50. Row 7"
		<< endl << "51. Row 8" << endl << "52. Row 9" << endl << "53. Row 10" << endl << "54. Row 11" << endl << "55. Row 12"
		<< endl << "56. 1-12" << endl << "57. 13-24" << endl << "58. 25-36" << endl;
	while (userChoice != 0)
	{
		cin >> userChoice;
		if (userChoice == 0)											//Spin the wheel!
		{
			cout << "Finalizing bets and spinning the wheel..." << endl;
			spinWheel();
		}
		else if (userChoice >= 1 && userChoice <= 36)					//Individual
		{
			cout << "You have bet on: " << userChoice << endl;
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 37)										//All odds
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 36; idx = idx + 2)
			{
				cout << idx + 2 << " ";
				rouletteChoice.push_back(userChoice);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 38)										//All evens
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 36; idx = idx + 2)
			{
				cout << idx + 1 << " ";
				rouletteChoice.push_back(userChoice);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 39)										//All black
		{
			cout << "You have bet on: ";
			rouletteChoice.push_back(2);
			cout << "2 ";
			rouletteChoice.push_back(4);
			cout << "4 ";
			rouletteChoice.push_back(6);
			cout << "6 ";
			rouletteChoice.push_back(8);
			cout << "8 ";
			rouletteChoice.push_back(10);
			cout << "10 ";
			rouletteChoice.push_back(11);
			cout << "11 ";
			rouletteChoice.push_back(13);
			cout << "13 ";
			rouletteChoice.push_back(15);
			cout << "15 ";
			rouletteChoice.push_back(17);
			cout << "17 ";
			rouletteChoice.push_back(20);
			cout << "20 ";
			rouletteChoice.push_back(22);
			cout << "22 ";
			rouletteChoice.push_back(24);
			cout << "24 ";
			rouletteChoice.push_back(26);
			cout << "26 ";
			rouletteChoice.push_back(28);
			cout << "28 ";
			rouletteChoice.push_back(29);
			cout << "29 ";
			rouletteChoice.push_back(31);
			cout << "31 ";
			rouletteChoice.push_back(33);
			cout << "33 ";
			rouletteChoice.push_back(35);
			cout << "35" << endl;
			cout << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 40)										//All red
		{
			cout << "You have bet on: ";
			rouletteChoice.push_back(1);
			cout << "1 ";
			rouletteChoice.push_back(3);
			cout << "3 ";
			rouletteChoice.push_back(5);
			cout << "5 ";
			rouletteChoice.push_back(7);
			cout << "7 ";
			rouletteChoice.push_back(9);
			cout << "9 ";
			rouletteChoice.push_back(12);
			cout << "12 ";
			rouletteChoice.push_back(14);
			cout << "14 ";
			rouletteChoice.push_back(16);
			cout << "16 ";
			rouletteChoice.push_back(18);
			cout << "18 ";
			rouletteChoice.push_back(19);
			cout << "19 ";
			rouletteChoice.push_back(21);
			cout << "21 ";
			rouletteChoice.push_back(23);
			cout << "23 ";
			rouletteChoice.push_back(25);
			cout << "25 ";
			rouletteChoice.push_back(27);
			cout << "27 ";
			rouletteChoice.push_back(30);
			cout << "30 ";
			rouletteChoice.push_back(32);
			cout << "32 ";
			rouletteChoice.push_back(34);
			cout << "34 ";
			rouletteChoice.push_back(36);
			cout << "36 " << endl;
			cout << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 41)										//Column 1
		{
			cout << "You have bet on: ";
			for (int idx = 1; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				rouletteChoice.push_back(idx);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 42)										//Column 2
		{
			cout << "You have bet on: ";
			for (int idx = 2; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				rouletteChoice.push_back(idx);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 43)										//Column 3
		{
			cout << "You have bet on: ";
			for (int idx = 3; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				rouletteChoice.push_back(idx);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 44)										//Row 1
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << (idx + 1) << " ";
				rouletteChoice.push_back(idx + 1);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 45)										//Row 2
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 4 << " ";
				rouletteChoice.push_back(idx + 4);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 46)										//Row 3
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 7 << " ";
				rouletteChoice.push_back(idx + 7);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 47)										//Row 4
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 10 << " ";
				rouletteChoice.push_back(idx + 10);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 48)										//Row 5
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 13 << " ";
				rouletteChoice.push_back(idx + 13);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 49)										//Row 6
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 16 << " ";
				rouletteChoice.push_back(idx + 16);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 50)										//Row 7
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 19 << " ";
				rouletteChoice.push_back(idx + 19);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 51)										//Row 8
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 22 << " ";
				rouletteChoice.push_back(idx + 22);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 52)										//Row 9
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 25 << " ";
				rouletteChoice.push_back(idx + 25);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 53)										//Row 10
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 28 << " ";
				rouletteChoice.push_back(idx + 28);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 54)										//Row 11
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 31 << " ";
				rouletteChoice.push_back(idx + 31);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 55)										//Row 12
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx++)
			{
				cout << idx + 34 << " ";
				rouletteChoice.push_back(idx + 34);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 56)										//1-12
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 12; idx++)
			{
				cout << (idx + 1) << " ";
				rouletteChoice.push_back(idx + 1);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 57)										//13-24
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 12; idx++)
			{
				cout << (idx + 13) << " ";
				rouletteChoice.push_back(idx + 13);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 58)										//25-36
		{
			cout << "You have bet on: ";
			for (short idx = 0; idx < 12; idx++)
			{
				cout << (idx + 25) << " ";
				rouletteChoice.push_back(idx + 25);
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else															//Unrecognized
		{
			cout << "Not able to handle" << endl;
		}
	}
}

void RouletteTable::spinWheel()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<short> dist(1, 36);
	randomSpin = dist(mt);
	cout << "The wheel has spun: " << randomSpin << endl;
	determineWin();
}

void RouletteTable::determineWin()
{
	if (find(rouletteChoice.begin(), rouletteChoice.end(), randomSpin) != rouletteChoice.end())
	{
		cout << "User wins!" << endl;
	}
	else
	{
		cout << "User loses" << endl;
	}
}