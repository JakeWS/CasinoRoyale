#include <iostream>
#include <random>

using namespace std;

class RouletteTable {
private:
public:
	RouletteTable();
	~RouletteTable();
	void displayTable();
	void spinWheel();
	void determineWin();
	void takeBets();
};

int main()
{
	RouletteTable newRoulette;
}

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
		if ((idx + 4) % 2 == 0)
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
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 38)										//All evens
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 36; idx = idx + 2)
			{
				cout << idx + 1 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 39)										//All black
		{

		}
		else if (userChoice == 40)										//All red
		{

		}
		else if (userChoice == 41)										//Column 1
		{
			cout << "You have bet on: ";
			for (int idx = 1; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 42)										//Column 2
		{
			cout << "You have bet on: ";
			for (int idx = 2; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 43)										//Column 3
		{
			cout << "You have bet on: ";
			for (int idx = 3; idx < 36; idx = idx + 3)
			{
				cout << idx << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 44)										//Row 1
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 1 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 45)										//Row 2
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 2 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 46)										//Row 3
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 3 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 47)										//Row 4
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 4 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 48)										//Row 5
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 5 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 49)										//Row 6
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 6 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 50)										//Row 7
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 7 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 51)										//Row 8
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 8 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 52)										//Row 9
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 9 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 53)										//Row 10
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 10 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 54)										//Row 11
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 11 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 55)										//Row 12
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 3; idx = idx++)
			{
				cout << (idx + 1) * 12 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 56)										//1-12
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 12; idx++)
			{
				cout << (idx + 1) * 1 << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 57)										//13-24
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 12; idx++)
			{
				cout << (idx + 13) << " ";
				//push
			}
			cout << endl << "What else would you like to bet on:" << endl;
		}
		else if (userChoice == 58)										//25-36
		{
			cout << "You have bet on: ";
			for (int idx = 0; idx < 12; idx++)
			{
				cout << (idx + 25) << " ";
				//push
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

}

void RouletteTable::determineWin()
{

}