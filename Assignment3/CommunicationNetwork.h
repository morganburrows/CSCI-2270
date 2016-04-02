#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>

struct City
{
    std::string cityname;
    std::string message;
    City *next;
    City *prev;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrev, std::string initMessage)
    {
        cityname = initName;
        next = initNext;
        prev = initPrev;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addcity(std::string, std::string);
        void subcity(std::string);
        void buildnet();
        void clearnet();
        void transmit(char *); //this is like a string
        void dispath();
    protected:
    private:
        bool isbuilt = false;
        City *head;
        City *tail;
};

//CommunicationNetwork::CommunicationNetwork();

#endif // COMMUNICATIONNETWORK_H
