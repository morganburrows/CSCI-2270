#include "Queue.h"

using namespace std;

Queue::Queue(int qs)
{
    queuesize = qs;
    arrayqueue = new string[queuesize];
    queuehead = 0;
    queuetail = 0;
}
Queue::~Queue()
{

}


bool Queue::isfull()
{
    if(queuecount == queuesize)
    {
        return true;
    }
    return false;
}
bool Queue::isempty()
{
    if(queuecount == 0)
    {
        return true;
    }
    return false;
}


void Queue::enqueue(std::string inword)
{

    if(!isfull())
    {
        arrayqueue[queuetail %queuesize] = inword;
        queuetail = queuetail+1;

        cout<<"E: "<<inword<<endl;
        cout<<"H: "<<queuehead %queuesize<<endl;
        cout<<"T: "<<queuetail %queuesize<<endl;

        queuecount = queuecount+1;
    }
    else if(isfull())
    {
        cout<<"Queue is full."<<endl;
    }
}

std::string Queue::dequeue()
{
    if(isempty())
    {
        cout<<"Queue is empty."<<endl;
    }
    else if(!isempty())
    {
        cout<<"H: "<<queuehead+1 %queuesize<<endl;
        cout<<"T: "<<queuetail %queuesize<<endl;
        cout<<"word: "<<arrayqueue[queuehead %queuesize]<<endl;

        arrayqueue[queuehead %queuesize] = "";
        queuehead = queuehead + 1;
        queuecount = queuecount-1;
    }
    return arrayqueue[queuehead %queuesize];
}

void Queue::printqueue()
{
    if(!isempty())
    {
        for(int a = queuehead; a < queuetail; a++)
        {
            cout<<a %queuesize<<": "<<arrayqueue[a %queuesize]<<endl;
        }
    }
    else if(isempty())
    {
        cout<<"Empty"<<endl;
    }

}

void Queue::sentenqueue()
{
    cout<<"sentence: ";
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin,readin);
    stringstream ss(readin);

    while(ss >> inword)
    {
        enqueue(inword);
    }
}
