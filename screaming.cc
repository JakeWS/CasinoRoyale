//CS310 Jake Watts-Squires
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class SlotMachine{
  private:
    vector<int> slots[5];
    double returnAmount;
    vector<int> threeByThreeSlotPayouts[5] = {{9,9,9},{9,8,9},{8,8,8},{8,7,8},{7,7,7}};
    vector<int> fourByFourSlotPayouts[5] = {{9,9,9,9},{9,8,8,9},{8,8,8,8},{8,7,7,8},{7,7,7,7}};
    vector<int> fiveByFiveSlotPayouts[5] = {{9,9,9,9,9},{9,8,8,8,9},{8,8,8,8,8},{8,8,7,8,8},{7,7,7,7,7}};
  public:
    SlotMachine();
    ~SlotMachine();
    void threeByThree();
    void fourByFour();
    void fiveByFive();        
    void rollSlot();
    void readSlot();
    void determine3x3Winnings();
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
            threeByThree();
        }
        else if(userChoice == 2)
        {
          fourByFour();
        }
        else if(userChoice == 3)
        {
          fiveByFive();
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
            rollSlot();
            readSlot();
            determine3x3Winnings();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::fourByFour()
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
            determine3x3Winnings();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }

    }
}

void SlotMachine::fiveByFive()
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
            determine3x3Winnings();
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
    int rows = 3;
    int columns = 5;
    for(int idx1 = 0; idx1 < rows; idx1++)
    {
        this->slots[idx1].clear();
        for(int idx2 = 0; idx2 < columns; idx2++)
        {
          uniform_int_distribution<int> dist(0, 9);
          this->slots[idx1].push_back(dist(mt));
        }
    }
}

void SlotMachine::readSlot()
{
    int rows = 3;
    int columns = 5;
    for(int idx1 = 0; idx1 < rows; idx1++)
    {
        for(int idx2 = 0; idx2 < columns; idx2++)
        {
            cout<<this->slots[idx1][idx2]<< "";
        }
        cout<<endl;
    }
}

void SlotMachine::determine3x3Winnings()
{
  /*int slotCheck[3];
  int slotMatches = 0;
  for (int idx1 = 0; idx1 < rows; idx1++)
  {
    for (int idx2 = 0; idx2 < columns; idx2++)
    {
      slotCheck[idx2] = this->slots[idx1][idx2];
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[0][0] && slotCheck[1] == threeByThreeSlotPayouts[0][1] && slotCheck[2] == threeByThreeSlotPayouts[0][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[1][0] && slotCheck[1] == threeByThreeSlotPayouts[1][1] && slotCheck[2] == threeByThreeSlotPayouts[1][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[2][0] && slotCheck[1] == threeByThreeSlotPayouts[2][1] && slotCheck[2] == threeByThreeSlotPayouts[2][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[3][0] && slotCheck[1] == threeByThreeSlotPayouts[3][1] && slotCheck[2] == threeByThreeSlotPayouts[3][2])
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
    if (slotCheck[0] == threeByThreeSlotPayouts[0][0] && slotCheck[1] == threeByThreeSlotPayouts[0][1] && slotCheck[2] == threeByThreeSlotPayouts[0][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[1][0] && slotCheck[1] == threeByThreeSlotPayouts[1][1] && slotCheck[2] == threeByThreeSlotPayouts[1][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[2][0] && slotCheck[1] == threeByThreeSlotPayouts[2][1] && slotCheck[2] == threeByThreeSlotPayouts[2][2])
    {
      slotMatches++;
    }
    if (slotCheck[0] == threeByThreeSlotPayouts[3][0] && slotCheck[1] == threeByThreeSlotPayouts[3][1] && slotCheck[2] == threeByThreeSlotPayouts[3][2])
    {
      slotMatches++;
    }
  }
  cout<<"Row & Column Matches: "<<slotMatches<<endl;*/  
}
