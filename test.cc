#include <iostream>     // std::cout
#include <fstream>
#include <random>
#include <vector>

using namespace std;

class SlotMachine {
private:
	vector<int> slotsFRow = {0,0,0,0,0};
	double returnAmount;
	int threeRowPayout[5][3] = { { 9,9,9 },{ 9,8,9 },{ 8,8,8 },{ 8,7,8 },{ 7,7,7 } };
	int fourRowPayout[5][4] = { { 9,9,9,9 },{ 9,8,8,9 },{ 8,8,8,8 },{ 8,7,7,8 },{ 7,7,7,7 } };
	int fiveRowPayout[5][5] = { { 9,9,9,9,9 },{ 9,8,8,8,9 },{ 8,8,8,8,8 },{ 8,8,7,8,8 },{ 7,7,7,7,7 } };
	int total3Match = 0;
	int total4Match = 0;
	int total5Match = 0;
public:
	SlotMachine();
	~SlotMachine();
	void rollSlot();	
	void det3RowWin();
	void det4RowWin();
	void det5RowWin();
};


int main () 
{
	SlotMachine newSlots;
}

SlotMachine::SlotMachine()
{
	rollSlot();
}

SlotMachine::~SlotMachine()
{
	cout << "Slot machine powered off." << endl;
}

void SlotMachine::rollSlot()
{
	ofstream myfile;
	for (int idx1 = 0; idx1 < 10; idx1++)
	{
		cout << idx1 << endl;
		for (int idx2 = 0; idx2 < 10; idx2++)
		{
			for (int idx3 = 0; idx3 < 10; idx3++)
			{
				for (int idx4 = 0; idx4 < 10; idx4++)
				{
					for (int idx5 = 0; idx5 < 10; idx5++)
					{
						this->slotsFRow[0] = idx5;
						this->slotsFRow[1] = idx4;
						this->slotsFRow[2] = idx3;
						this->slotsFRow[3] = idx2;
						this->slotsFRow[4] = idx1;
						det3RowWin();
						det4RowWin();
						det5RowWin();											
					}
				}
			}
		}
	}
	myfile.open("det3Row.txt", fstream::app);
	myfile << total3Match << " total matches!" << endl;
	myfile.close();
	myfile.open("det4Row.txt", fstream::app);
	myfile << total4Match << " total matches!" << endl;
	myfile.close();
	myfile.open("det5Row.txt", fstream::app);
	myfile << total5Match << " total matches!" << endl;
	myfile.close();

}

void SlotMachine::det3RowWin()
{
	ofstream myfile;
	myfile.open("det3Row.txt", fstream::app);
	bool hit = 0;
	short match = 0;
	for (int idx1 = 0; idx1 < 3; idx1++)
	{
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[idx1] == threeRowPayout[idx2][0] && slotsFRow[idx1 + 1] == threeRowPayout[idx2][1] && slotsFRow[idx1 + 2] == threeRowPayout[idx2][2])
			{
				hit = 1;
				match++;
				total3Match++;
			}
		}
	}
	if (hit == 1)
	{
		myfile << match <<" matches at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	else
	{
		myfile << "No match at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	myfile.close();

}

void SlotMachine::det4RowWin()
{
	ofstream myfile;
	myfile.open("det4Row.txt", fstream::app);
	bool hit = 0;
	short match = 0;
	for (int idx1 = 0; idx1 < 2; idx1++)
	{
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[idx1] == fourRowPayout[idx2][0] && slotsFRow[idx1 + 1] == fourRowPayout[idx2][1] && slotsFRow[idx1 + 2] == fourRowPayout[idx2][2] && slotsFRow[idx1 + 3] == fourRowPayout[idx2][3])
			{
				hit = 1;
				match++;
				total4Match++;
			}
		}
	}
	if (hit == 1)
	{
		myfile << match << " matches at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	else
	{
		myfile << "No match at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	myfile.close();
}

void SlotMachine::det5RowWin()
{
	ofstream myfile;
	myfile.open("det5Row.txt", fstream::app);

	bool hit = 0;
	short match = 0;
		for (int idx2 = 0; idx2 < 5; idx2++)
		{
			if (slotsFRow[0] == fiveRowPayout[idx2][0] && slotsFRow[1] == fiveRowPayout[idx2][1] && slotsFRow[2] == fiveRowPayout[idx2][2]
				&& slotsFRow[3] == fiveRowPayout[idx2][3] && slotsFRow[4] == fiveRowPayout[idx2][4])
			{
				hit = 1;
				match++;
				total5Match++;
			}
		}
	if (hit == 1)
	{
		myfile << match << " matches at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	else
	{
		myfile << "No match at:" << endl;
		for (int idx1 = 0; idx1 < 5; idx1++)
		{
			myfile << this->slotsFRow[idx1];
		}
		myfile << endl;
	}
	myfile.close();
}