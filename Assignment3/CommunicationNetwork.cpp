#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    //cstor
}
CommunicationNetwork::~CommunicationNetwork()
{
    void clearnet();
}


void CommunicationNetwork::buildnet()
{
//convert an array into a linked list
    string a[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis",
    "Chicago", "Atlanta", "Washington, D.C.", "New York","Boston"};

    head = new City(a[0], NULL, NULL, "");

    City *prev = head;
    head -> prev = NULL;

    for(int i = 1; i < 10; i++)
    {
        City *current = new City(a[i], NULL, NULL, "");

        prev -> next = current;
        current -> prev = prev;

        prev = current;
    }

    head -> next-> next-> next-> next-> next-> next -> next-> next-> next -> next = NULL;   //  make boston's NEXT be NULL

    City *current = head;
    cout<<"===CURRENT PATH==="<<	endl;
    cout<<"NULL <- ";
    while(current -> next != NULL)
    {
        cout<<current -> cityname<<" <-> ";
        current = current -> next;
    }
    cout<< current -> cityname<<" ->";
    cout<<" NULL"<<endl;
    cout<<"=================="<<endl;

    isbuilt = true;
}

void CommunicationNetwork::dispath()
{
    if(isbuilt == true)
    {
        City *current = head;
        cout<<"===CURRENT PATH==="<<endl;
        cout<<"NULL <- ";
        while(current -> next != NULL)
        {
            cout<<current -> cityname<<" <-> ";
            current = current -> next;
        }
        cout<< current -> cityname<<" -> ";
        cout<<"NULL"<<endl;
        cout<<"=================="<<endl;
    }
    else if(isbuilt == false)
    {
        cout<<"===CURRENT PATH==="<<endl;
        cout<<"NULL"<<endl;
        cout<<"=================="<<endl;
    }
}

void CommunicationNetwork::addcity(string newcityname, string prevcityname)
{
    if(isbuilt == true)
    {
        City *prev = head;
        City *temp = new City;

        cout<<"Enter a city name: "<<endl;
        cin.ignore();
        getline(cin,newcityname);
        cout<<"Enter a previous city name: "<<endl;
        getline(cin,prevcityname);

        if(prevcityname == "First")
        {
            temp -> prev = NULL;
            temp -> next = prev;
            prev -> prev = temp;
            head = temp;
            head -> cityname = newcityname;

        }
        else
        {
            while(prev -> cityname != prevcityname)
            {
                prev = prev->next;
            }

            temp -> next = prev -> next;
            temp -> prev = prev;
            temp -> next -> prev = temp;
            prev -> next = temp;

            temp -> cityname = newcityname;
        }

    }
    else if(isbuilt == false)
    {
        cout<<"The network has not been built yet."<<endl;
    }
}

void CommunicationNetwork::transmit(char *filein)
{
if(isbuilt == true)
    {
        string tempmsg;

        ifstream argfile;
        argfile.open(filein);

        while(argfile >> tempmsg)
        {
            City *msgpoint = head;

            while(msgpoint -> next != NULL)
            {
                msgpoint -> message = tempmsg;
                cout<<msgpoint -> cityname<<" received "<<msgpoint -> message<<endl;
                msgpoint = msgpoint -> next;
            }
            while(msgpoint != NULL)
            {
                msgpoint -> message = tempmsg;
                cout<<msgpoint -> cityname<<" received "<<msgpoint -> message<<endl;
                msgpoint = msgpoint -> prev;
            }
        }
    }
    else if(isbuilt == false)
    {
        cout<<"Empty list"<<endl;
    }
}

void CommunicationNetwork::clearnet()
{
    if(isbuilt == true)
    {
        City *current = head;
        City *temp;

        while(current -> next != NULL)
        {
            cout<<"deleting "<< current -> cityname<<endl;

            current = current -> next;
            temp = current -> prev;
            delete temp;
        }

        if(current -> next == NULL)
        {
            cout<<"deleting "<< current -> cityname<<endl;
            delete current;
            isbuilt = false;
        }
    }
    else if(isbuilt == false)
    {
        //cout<<"The network has not been built yet."<<endl;
    }
}

void CommunicationNetwork::subcity(string subcityname)
{
    if(isbuilt == true)
    {
        City *current  = head;

        cout<<"Enter a city name: "<<endl;
        cin.ignore();
        getline(cin,subcityname);

        while(current -> cityname != subcityname)
        {
            current = current->next;

            if(current -> cityname == subcityname && current -> next == NULL)
            {
                current -> prev -> next = NULL;
                delete current;
            }

            if(current -> cityname == subcityname && current -> next != NULL)
            {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
                delete current;
            }
            else if(current -> next == NULL)
            {
                //cout<<current -> cityname<<" not found"<<endl;
                break;
            }
        }




    }
    else if(isbuilt == false)
    {
        cout<<"The network has not been built yet."<<endl;
    }
}



