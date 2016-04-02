#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue newqueue(10);

    string inword;
    bool proggo = false;

    do  //  main menu
    {
        int minput;
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<< endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;

        cin >> minput;

        switch(minput)  //  main switch for menu input
        {
            case 1:
            cout<<"word: ";
            cin.ignore();
            getline(cin,inword);
            newqueue.enqueue(inword);
            proggo = true;
            break;

            case 2: newqueue.dequeue();
            proggo = true;
            break;

            case 3: newqueue.printqueue();
            proggo = true;
            break;

            case 4: newqueue.sentenqueue();
            proggo = true;
            break;

            case 5: cout<<"Goodbye!"<<endl;
            exit(0);
            break;

            default:
            proggo = false;
        }
    }
    while(proggo == true);
}
