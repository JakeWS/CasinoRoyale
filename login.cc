#include <iostream>

using namespace std;

class logIn{
  private:
    string userName;
    string passWord;
    bool serverReturn;
  public:
    logIn();
    ~logIn();
};


/*
int main()
{
    logIn newLogin;
}*/

//Slot Machine
logIn::logIn()
{
    bool continueLoop = 1;
    while (continueLoop)
    {
        cout<<"Please enter username: ";
        cin>>userName;
        cout<<"Please enter password: ";
        cin>>passWord;
        /*Sending the username and password to server function here*/
        /*For testing purposes, will allow for user input into `serverReturn`*/
        cin>>serverReturn;
        if (serverReturn == 0)
        {
            cout<<"Unable to login, please retry logging in."<<endl;
        }
        else if (serverReturn == 1)
        {
            cout<<"Sucessful login!"<<endl;
            continueLoop = 0;
        }
        else
        {
            cout<<"Unexpected error, please try again"<<endl;
        }
    }
}

logIn::~logIn()
{
    serverReturn = 0;
    cout<<"Logged out."<<endl;
}