// Options.cc

#include <iostream>
#include "graphics.h"

using namespace std;

class Options
{
  private:

  public:
    bool continueLoop;
    int userAction;
    int userFont;
    int userChoice;
    Options();  // constructor
    //int setFont(); // in graphics.hpp
    //int setColor();  // in graphics.hpp
};
// test driver

// # defines for "magic numbers"
// use enumeration and implement switch and case instead of if else
  // change the numbers ionto # defines

  //

int main()
{
  Options newOptions;
}

Options::Options()
{
  bool continueLoop = true;
  int userAction;  // users action to choose to change font / Color / DN
  int userFont;    // users font choice
  int userChoice;  // users color choice

  while(continueLoop)
  {
    std::cout<<"What would you like to do?"<<std::endl<<"0. Exit Options."<<std::endl<<"1. Change Font."<<std::endl<<"2. Change Font Color."<<std::endl;
    std::cin>> userAction;

    if(userAction == 0)
    {
      std::cout<<"Exiting Options Menu...."<<std::endl;
      continueLoop = false;
    }
    else if(userAction == 1)
    {
      std::cout<<"Which of the following fonts would you like to use?"<<std::endl<<"0.I do not want to change my font."<<std::endl<<"1. Font1"<<std::endl<<"2. Font2"<<std::endl;
      std::cin>>userFont;

      //if else block for each of the fonts
      if(userFont == 0)
      {
        std::cout<<"Keeping Font Choice unaltered."<<std::endl;
        //continueLoop = false
      }
      else if(userFont == 1)
      {
        std::cout<<"Setting font to desired font choice..."<<std::endl;
        //set font function
        setFont(1);
      }
      else if(userFont == 2)
      {
        std::cout<<"Setting font to desired font choice..."<<std::endl;
        //set font function
        setFont(2);
      }
      else
      {
        std::cout<<"Unable to process, please respond to the promp again."<<std::endl;
      }
    }
    else if(userAction == 2)
    {
      std::cout<<"Which of the following font colors would you like to implement?"<<std::endl<<"0. No color change."<<std::endl<<"1. Color1"<<std::endl<<"2. Color2"<<std::endl;
      std::cin>>userChoice;

      //if else block for color choices
      if(userChoice == 0)
      {
        std::cout<<"Keeping font color unaltered..."<<std::endl;

      }
      else if(userChoice == 1)  // Color 1
      {
        std::cout<<"Setting font color to desired color..."<<std::endl;
        //set color function
      }
      else if(userChoice == 2)  // Color2
      {
        std::cout<<"Setting font color to desired color..."<<std::endl;
        //set color function
      }
      else
      {
        std::cout<<"Unable to process, please respond to the promp again."<<std::endl;
      }
    }
    else
    {
      std::cout<<"Unable to process, please respond to the promp again."<<std::endl;
    }
  }


}
