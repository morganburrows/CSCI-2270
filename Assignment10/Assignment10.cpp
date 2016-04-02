#include "Graph.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[])
{
    string cityname,city;

    ifstream filein;
    filein.open(argv[1]);

    if(filein.good())   //  File input and getlines
    {
        while(getline(filein,cityname))
        {
            cout<<cityname<<endl;
            stringstream ss(cityname);
            while(getline(ss,city,','))
            {
                cout<<city<<endl;
            }
        }
    }



    bool proggo = false;

    do  //  main menu
    {
        int minput;
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Print vertices"<<endl;
        cout<<"2. Find districts"<<endl;
        cout<<"3. Find shortest path"<< endl;
        cout<<"4. Quit"<<endl;

        cin >> minput;

        switch(minput)  //  main switch for menu input
        {
            case 1:
                proggo = true;
                break;

            case 2:
                proggo = true;
                break;

            case 3:
                proggo = true;
                break;

            case 4:
                cout<<"Goodbye!"<<endl;
                exit(0);
                break;

            default:
            proggo = false;
        }
    }
    while(proggo == true);
}
