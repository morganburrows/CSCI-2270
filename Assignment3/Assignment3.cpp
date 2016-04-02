//  Morgan Burrows
//  CSCI 2270
//  Dr. Rhonda Hoenigman
//  Upandra sabnis
//  [date]
//  [Assignment 3]

#include "CommunicationNetwork.h"

using namespace std;

int main(int argc, char *argv[])
{

CommunicationNetwork network = CommunicationNetwork();

string subcityname;
string newcityname;
string prevcityname;
bool proggo = false;

do  //  main menu
{
    int minput;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast-To-Coast"<< endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Delete City"<<endl;
    cout<<"6. Clear Network"<<endl;
    cout<<"7. Quit"<<endl;

    cin >> minput;
    if(minput == 1||2||3||4||5) //  proceed if user input is of expected range
    {
        switch(minput)  //  main switch for menu input
        {
            case 1: network.buildnet();
            proggo = true;
            break;

            case 2: network.dispath();
            proggo = true;
            break;

            case 3: network.transmit(argv[1]);
            proggo = true;
            break;

            case 4: network.addcity(newcityname, prevcityname);
            proggo = true;
            break;

            case 5: network.subcity(subcityname);
            proggo = true;
            break;

            case 6: network.clearnet();
            proggo = true;
            break;

            case 7: cout<<"Goodbye!"<<endl;
            network.clearnet();
            exit(0);
            break;

            default:
            proggo = false;
        }
    }
    else if(minput != 1||2||3||4||5)    //  if not of expected range, output error and wait for correct input
    {
        cout<<"Please choose a number between 1 and 5"<<endl;
        proggo = true;
    }

}
while(proggo == true);


}
