//CS310 Jake Watts-Squires
#include <iostream>
#include <random>

using namespace std;

class SlotMachine{
  private:
    int slots[5][5];
    double returnAmount;
    int slotPayouts[4][3] = {{9,9,9},{8,8,8,},{8,7,8},{7,7,7}};
  public:
    SlotMachine();
    ~SlotMachine();
    void threeByThree();
    void rollSlot(int rows, int columns);
    void readSlot(int rows, int columns);
    void determineWinnings(int rows, int columns);
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
        cout<<"What would you like to play with?"<<endl<<"0. Exit"<<endl<<"1. 3x3"<<endl;
        cin>>userChoice;
        if(userChoice == 0)
        {
            cout<<"Exiting"<<endl;
            continueLoop = 0;
        }
        else if(userChoice == 1)
        {
            threeByThree();
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

void SlotMachine::threeByThree()
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
            rollSlot(rows, columns);
            readSlot(rows, columns);
            determineWinnings(rows, columns);
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::rollSlot(int rows, int columns)
{
    random_device rd;
    mt19937 mt(rd());
    for(int idx1 = 0; idx1 < rows; idx1++)
    {
        for(int idx2 = 0; idx2 < columns; idx2++)
        {
          uniform_int_distribution<int> dist(0, 9);
          this->slots[idx1][idx2] = dist(mt);
        }
    }
}

void SlotMachine::readSlot(int rows, int columns)
{
    for(int idx1 = 0; idx1 < rows; idx1++)
    {
        for(int idx2 = 0; idx2 < columns; idx2++)
        {
            cout<<this->slots[idx1][idx2]<< "";
        }
        cout<<endl;
    }
}

void SlotMachine::determineWinnings(int rows, int columns)
{
  int slotCheck[3];
  int slotMatches = 0;
  for (int idx1 = 0; idx1 < rows; idx1++)
  {
    for (int idx2 = 0; idx2 < columns; idx2++)
    {
      slotCheck[idx2] = this->slots[idx1][idx2];
    }
    if (slotCheck[0] == slotPayouts[0][0] && slotCheck[1] == slotPayouts[0][1] && slotCheck[2] == slotPayouts[0][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[1][0] && slotCheck[1] == slotPayouts[1][1] && slotCheck[2] == slotPayouts[1][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[2][0] && slotCheck[1] == slotPayouts[2][1] && slotCheck[2] == slotPayouts[2][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[3][0] && slotCheck[1] == slotPayouts[3][1] && slotCheck[2] == slotPayouts[3][2])
    {
      slotMatches++;
    }
  }
  for (int idx1 = 0; idx1 < columns; idx1++)
  {
    for (int idx2 = 0; idx2 < rows; idx2++)
    {
      slotCheck[idx2] = this->slots[idx2][idx1];
    }
    if (slotCheck[0] == slotPayouts[0][0] && slotCheck[1] == slotPayouts[0][1] && slotCheck[2] == slotPayouts[0][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[1][0] && slotCheck[1] == slotPayouts[1][1] && slotCheck[2] == slotPayouts[1][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[2][0] && slotCheck[1] == slotPayouts[2][1] && slotCheck[2] == slotPayouts[2][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == slotPayouts[3][0] && slotCheck[1] == slotPayouts[3][1] && slotCheck[2] == slotPayouts[3][2])
    {
      slotMatches++;
    }
  }
  cout<<"Row & Column Matches: "<<slotMatches<<endl;  
}
