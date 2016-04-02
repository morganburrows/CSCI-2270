#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <sstream>


class Queue
{
    public:
        Queue(int);
        ~Queue();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printqueue();
        void sentenqueue();
        bool isfull(); //send when full
        bool isempty(); //send when empty
        std::string inword;
        std::string readin;
        std::string temp;
        int queuecount = 0;

    protected:
    private:
        int queuesize;
        int queuehead;
        int queuetail;
        //int queuecount = 0;
        std::string *arrayqueue;
};

#endif // QUEUE_H
