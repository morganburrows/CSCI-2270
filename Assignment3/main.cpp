#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    string cityname;
    int netpos;
    string message;
};

bool proggo = false;

void buildnet ()
{
    cout<<"flag1"<<endl;
}

void dispath ()
{
    cout<<"flag2"<<endl;
}

void transmit ()
{
    cout<<"flag3"<<endl;
}

void addcity()
{
    cout<<"flag4"<<endl;
}

int main()  //  begin application, output menu
{

do
{
    int minput;
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<< endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;

    cin >> minput;
    switch(minput)  //  main switch for menu input
    {
        case 1: buildnet();
        proggo = true;
        break;
        case 2: dispath();
        break;
        case 3: transmit();
        break;
        case 4: addcity();
        break;
        case 5: exit(0);
        break;
        default:
        proggo = false;
    }
}
while(proggo == true)


;}   //  end of main
