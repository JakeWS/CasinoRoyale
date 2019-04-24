#include <iostream>
#include "slots.h"
#include "login.h"
#include "roulette.h"

using namespace std;

class mainMenu{
  private:
  public:
    mainMenu();
    ~mainMenu();
    void menuOptions();
    void playGames();
};

int main()
{
    mainMenu newMenu;
}

//Main menu
mainMenu::mainMenu()
{
    int menuChoice;
    bool menuContinue = 1;
    logIn newLogin;
    while (menuContinue)
    {
        cout<<"What would you like to do?"<<endl<<"0. Exit"<<endl<<"1. Play Games"<<endl<<"2. Options"<<endl;
        cin>>menuChoice;
        if(menuChoice == 0)
        {
            menuContinue = 0;
        }
        else if (menuChoice == 1)
        {
            playGames();
        }
        else if (menuChoice == 2)
        {
            menuOptions();
        }
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }
    }
    
}

mainMenu::~mainMenu()
{
    cout<<"Closing client."<<endl;
}

void mainMenu::menuOptions()
{
    cout<<"Options will be implemented here."<<endl;
}

void mainMenu::playGames()
{
    int gameChoice;
    bool gameContinue = 1;
    while (gameContinue)
    {
        cout<<"What would you like to play?"<<endl<<"0. Exit"<<endl<<"1. Slots"<<endl<<"2. Roulette"<<endl;
        cin>>gameChoice;
        if (gameChoice == 0)
        {
            cout<<"Exiting."<<endl;
            gameContinue = 0;
        }
        else if (gameChoice == 1)
        {
            SlotMachine newSlots;
        }
		else if (gameChoice == 2)
		{
			RouletteTable newRoulette;
		}
        else
        {
            cout<<"Unable to process, please respond to the prompt again."<<endl;            
        }
    }
}