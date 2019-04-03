// Options.cc

#include <iostream>
#include <graphics.h>

using namespace.std;

class Options
{
  private:

  public:
    bool usedAction;
    bool userFont;
    Options();  // constructor
    void changeFont(); //uses graphics.h
    void changeColor();  // uses graphics.h

    /********************
     * implement these (?) probs defer tbh
     * textheight();
     * textwidth();
     * setcolor();
     *******************/
};


int main()
{
  Options newOptions();
}

Options::Options();
{
  bool continueLoop = true;
  bool userAction;  // users action to choose to change font / Color / DN
  bool userFont;    // users font choice
  bool userChoice;  // users color choice

  while(continueLoop)
  {
    cout<<"What would you like to do?"<<endl<<"0. Exit Options."<<endl<<"1. Change Font."<<endl<<"2. Change Font Color."<<endl;
    cin>> userAction;

    if(userAction == 0)
    {
      cout<<"Exiting Options Menu...."<<endl;
      continueLoop = false;
    }
    else if(userAction == 1)
    {
      cout<<"Which of the following fonts would you like to use?"<<endl<<"0.I do not want to change my font."<<endl<<"1. Font1"<<endl<<"2. Font2"<<endl;
      cin>>userFont;

      //if else block for each of the fonts
      if(userFont == 0)
      {
        cout<<"Keeping Font Choice unaltered."<<endl;
        //continueLoop = false
      }
      else if(userFont == 1)
      {
        cout<<"Setting font to desired font choice..."<<endl;
        //set font function
      }
      else if(userFont == 2)
      {
        cout<<"Setting font to desired font choice..."<<endl;
        //set font function
      }
      else
      {
        cout<<"Unable to process, please respond to the promp again."<<endl;
      }
    }
    else if(userAction == 2)
    {
      cout<<"Which of the following font colors would you like to implement?"<<endl<<"0. No color change."<<endl<<"1. Color1"<<endl<<"2. Color2"<<endl;
      cin>>userChoice;

      //if else block for color choices
      if(userChoice == 0)
      {
        cout<<"Keeping font color unaltered..."<<endl;

      }
      else if(userChoice == 1)  // Color 1
      {
        cout<<"Setting font color to desired color..."<<endl;
        //set font function
      }
      else if(userChoice == 2)  // Color2
      {
        cout<<"Setting font color to desired color..."<<endl;
        //set font function
      }
      else
      {
        cout<<"Unable to process, please respond to the promp again."<<endl;
      }
    }
    else
    {
      cout<<"Unable to process, please respond to the promp again."<<endl;
    }
  }


}
