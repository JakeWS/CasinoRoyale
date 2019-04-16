#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class SlotMachine{
  private:
	vector<int> slotsFRow = {};
	vector<int> slotsSRow = {};
	vector<int> slotsTRow = {};
    double returnAmount;
    int threeRowPayout[5][3] = {{9,9,9},{9,8,9},{8,8,8},{8,7,8},{7,7,7}};
	int fourRowPayout[5][4] = {{9,9,9,9},{9,8,8,9},{8,8,8,8},{8,7,7,8},{7,7,7,7} };
	int fiveRowPayout[5][5] = {{9,9,9,9,9},{9,8,8,8,9},{8,8,8,8,8},{8,8,7,8,8},{7,7,7,7,7}};
  public:
    SlotMachine();
    ~SlotMachine();
    void threeRowSpin();
    void fourRowSpin();
    void fiveRowSpin();        
    void rollSlot();
    void readSlot();
    void det3RowWin();
	void det4RowWin();
	void det5RowWin();
};

/*int main()
{
  SlotMachine newSlots;
  
}*/

//Slot Machine
SlotMachine::SlotMachine()
{
    bool continueLoop = 1;
    int userChoice;
    while(continueLoop)
    {
        cout<<"What would you like to play with?"<<endl<<"0. Exit"<<endl<<"1. 3x3"<<endl<<"2. 4x4"<<endl<<"3. 5x5"<<endl;
        cin>>userChoice;
        if(userChoice == 0)
        {
            cout<<"Exiting"<<endl;
            continueLoop = 0;
        }
        else if(userChoice == 1)
        {
            threeRowSpin();
        }
        else if(userChoice == 2)
        {
          fourRowSpin();
        }
        else if(userChoice == 3)
        {
          fiveRowSpin();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;
        }
    }
}
SlotMachine::~SlotMachine()
{
  cout<<"Slot machine powered off."<<endl;
}

void SlotMachine::threeRowSpin()
{
    int rows = 3;
    int columns = 3;
    bool continueLoop = 1;
    int userChoice;
    while(continueLoop)
    {
        cout<<"What would you like to do?"<<endl<<"0. Exit"<<endl<<"1. Pull the lever"<<endl;
        cin>>userChoice;
        if(userChoice == 0)
        {
            cout<<"Exiting"<<endl;
            continueLoop = 0;
        }
        else if(userChoice == 1)
        {
            rollSlot();
            readSlot();
            det3RowWin();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::fourRowSpin()
{
    int rows = 4;
    int columns = 4;
    bool continueLoop = 1;
    int userChoice;
    while(continueLoop)
    {
        cout<<"What would you like to do?"<<endl<<"0. Exit"<<endl<<"1. Pull the lever"<<endl;
        cin>>userChoice;
        if(userChoice == 0)
        {
            cout<<"Exiting"<<endl;
            continueLoop = 0;
        }
        else if(userChoice == 1)
        {
            rollSlot();
            readSlot();
            det4RowWin();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::fiveRowSpin()
{
    int rows = 5;
    int columns = 5;
    bool continueLoop = 1;
    int userChoice;
    while(continueLoop)
    {
        cout<<"What would you like to do?"<<endl<<"0. Exit"<<endl<<"1. Pull the lever"<<endl;
        cin>>userChoice;
        if(userChoice == 0)
        {
            cout<<"Exiting"<<endl;
            continueLoop = 0;
        }
        else if(userChoice == 1)
        {
            rollSlot();
            readSlot();
            det5RowWin();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::rollSlot()
{
    random_device rd;
    mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 9);
        this->slotsFRow.clear();
		this->slotsSRow.clear();
		this->slotsTRow.clear();
        for(int idx2 = 0; idx2 < 5; idx2++)
        {
          this->slotsFRow.push_back(dist(mt));
		  this->slotsSRow.push_back(dist(mt));
		  this->slotsTRow.push_back(dist(mt));
        }
}

void SlotMachine::readSlot()
{
        for(int idx1 = 0; idx1 < 5; idx1++)
        {
            cout<<this->slotsFRow[idx1]<< "";
        }
		cout << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			cout << this->slotsSRow[idx1]<< "";
		}
        cout<<endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			cout << this->slotsTRow[idx1] << "";
		}
		cout << endl;
}

void SlotMachine::det3RowWin()
{
	short slotsMatches = 0;
	for (int idx1 = 0; idx1 < 3; idx1++)
	{
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[idx1] == threeRowPayout[idx2][0] && slotsFRow[idx1 + 1] == threeRowPayout[idx2][1] && slotsFRow[idx1 + 2] == threeRowPayout[idx2][2])
			{
				cout << "Match found in row 1!" << endl;
				slotsMatches++;
			}
			if (slotsSRow[idx1] == threeRowPayout[idx2][0] && slotsSRow[idx1 + 1] == threeRowPayout[idx2][1] && slotsSRow[idx1 + 2] == threeRowPayout[idx2][2])
			{
				cout << "Match found in row 2!" << endl;
				slotsMatches++;
			}
			if (slotsTRow[idx1] == threeRowPayout[idx2][0] && slotsTRow[idx1 + 1] == threeRowPayout[idx2][1] && slotsTRow[idx1 + 2] == threeRowPayout[idx2][2])
			{
				cout << "Match found in row 3!" << endl;
				slotsMatches++;
			}
		}
	}
	cout << slotsMatches << " found in your roll!" << endl;
}

void SlotMachine::det4RowWin()
{
	short slotsMatches = 0;
	for (int idx1 = 0; idx1 < 2; idx1++)
	{
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[idx1] == fourRowPayout[idx2][0] && slotsFRow[idx1 + 1] == fourRowPayout[idx2][1] && slotsFRow[idx1 + 2] == fourRowPayout[idx2][2] && slotsFRow[idx1 + 3] == fourRowPayout[idx2][3])
			{
				cout << "Match found in row 1!" << endl;
				slotsMatches++;
			}
			if (slotsSRow[idx1] == fourRowPayout[idx2][0] && slotsSRow[idx1 + 1] == fourRowPayout[idx2][1] && slotsSRow[idx1 + 2] == fourRowPayout[idx2][2] && slotsSRow[idx1 + 3] == fourRowPayout[idx2][3])
			{
				cout << "Match found in row 2!" << endl;
				slotsMatches++;
			}
			if (slotsTRow[idx1] == fourRowPayout[idx2][0] && slotsTRow[idx1 + 1] == fourRowPayout[idx2][1] && slotsTRow[idx1 + 2] == fourRowPayout[idx2][2] && slotsTRow[idx1 + 3] == fourRowPayout[idx2][3])
			{
				cout << "Match found in row 3!" << endl;
				slotsMatches++;
			}
		}
	}
	cout << slotsMatches << " found in your roll!" << endl;
}


void SlotMachine::det5RowWin()
{
	short slotsMatches = 0;
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[0] == fiveRowPayout[idx2][0] && slotsFRow[1] == fiveRowPayout[idx2][1] && slotsFRow[2] == fiveRowPayout[idx2][2]
				&& slotsFRow[3] == fiveRowPayout[idx2][3] && slotsFRow[4] == fiveRowPayout[idx2][4])
			{
				cout << "Match found in row 1!" << endl;
				slotsMatches++;
			}
			if (slotsSRow[0] == fiveRowPayout[idx2][0] && slotsSRow[1] == fiveRowPayout[idx2][1] && slotsSRow[2] == fiveRowPayout[idx2][2]
				&& slotsSRow[3] == fiveRowPayout[idx2][3] && slotsSRow[4] == fiveRowPayout[idx2][4])
			{
				cout << "Match found in row 2!" << endl;
				slotsMatches++;
			}
			if (slotsTRow[0] == fiveRowPayout[idx2][0] && slotsTRow[1] == fiveRowPayout[idx2][1] && slotsTRow[2] == fiveRowPayout[idx2][2]
				&& slotsTRow[3] == fiveRowPayout[idx2][3] && slotsTRow[4] == fiveRowPayout[idx2][4])
			{
				cout << "Match found in row 3!" << endl;
				slotsMatches++;
			}
		}
	cout << slotsMatches << " found in your roll!" << endl;
}