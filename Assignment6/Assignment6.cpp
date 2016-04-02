#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char* argv[])
{
    MovieTree tree = MovieTree();
    int movrank, movyear, movquant;
    int tick = 0;
    string movtitle, movline, movword, inmov, rinmov;

    ifstream filein;
    filein.open(argv[1]);

    if(filein.good())   //  File inout and getlines
    {
        while(getline(filein,movline))
        {
            tick = 0;
            stringstream ss(movline);
            while(getline(ss,movword,','))
            {
                if(tick == 0)
                {
                    movrank = atoi(movword.c_str());
                }
                else if(tick == 1)
                {
                    movtitle = movword;
                }
                else if(tick == 2)
                {
                     movyear = atoi(movword.c_str());
                }
                else if(tick == 3)
                {
                    movquant = atoi(movword.c_str());
                }
                tick = tick+1;

            }
        tree.addMovieNode(movrank, movtitle, movyear, movquant);
        }
    }

    bool proggo = false;

    do  //  main menu
    {
        int minput;
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<< endl;
        cout<<"4. Quit"<<endl;

        cin >> minput;

        switch(minput)  //  main switch for menu input
        {
            case 1: cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin,inmov);
            tree.findMovie(inmov);
            proggo = true;
            break;

            case 2: cout<<"Enter title:"<<endl;
            cin.ignore();
            getline(cin,rinmov);
            tree.rentMovie(rinmov);
            proggo = true;
            break;

            case 3: tree.printMovieInventory();
            proggo = true;
            break;

            case 4: cout<<"Goodbye!"<<endl;
            exit(0);
            break;

            default:
            proggo = false;
        }
    }
    while(proggo == true);
}
