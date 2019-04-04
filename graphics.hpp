/***************************************
 * Graphics header file
 * Coded by Elizabeth Soechting
 * for Casino Royale Project
 * SE 310 & SE 420
 ***************************************/

// g prof 

#ifndef graphics_h
#define graphics_h

#include <iostream>

using namespace std;


class Graphics
{
  private:
  public:
    void setColor();
    bool colorLoop;
    int userColor;
    void setFont();
    bool fontLoop;
    int userfont;
};

void Graphics::setFont()
{
  cout<<"Set Font Function"<<endl;

  bool fontLoop = true;

  cout<<"What font would you like to choose?"<<endl<<"0. I do not want to change my font."<<endl<<"1. Inconsolata"<<endl<<"2. Comic Sans"<<endl;
  cin>>userfont;

  if(userfont == 0)
  {
    cout<<"Keeping font unaltered...."<<endl;
    fontLoop = false;
  }
  else if(userfont == 1)
  {
    // set font to font 1

  }
  else if(userfont == 2)
  {
    // set font to font 2

  }
  else
  {
    cout<<"Unable to process, please respond to the prompt again."<<endl;
  }

}

void Graphics::setColor()
{
  cout<<"Set Color Function"<<endl;

  bool colorLoop = true;

  cout<<"What color would you like to choose?"<<endl<<"0. I do not want to change the color."<<"1. Red"<<endl<<"2. Green"
  cin>>userColor;

  if(userColor == 0)
  {
    //not changing colors
    cout<<"Keeping text color unaltered..."<<endl;
    colorLoop = false;
  }
  else if(userColor == 1)
  {
    // green = "\x1b[32m"
    // printf("\x1b[32m green text on regular background \x1b[0m  \n");
    cout<<"\x1b[32m Your text is now Green!"<<endl;

  }
  else if(userColor == 2)
  {
    // red = "\x1b[31m"
    // printf("\x1b[31m red text on regular background \x1b[0m  \n");
    cout<<"\x1b[31m Your text is now Red!"<<endl;
  }
  else
  {
    cout<<"Unable to process, please respond to the prompt aagin."<<endl;
  }
}
// lib curses -  conttrols how thigns look on CLI
// g vim
// main program test drivers
//

#endif
