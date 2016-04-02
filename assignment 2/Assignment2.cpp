//  Morgan Burrows
//  CSCI 2270
//  Dr. Rhonda Hoenigman
//  Upandra sabnis
//  [date]
//  [Hunger Games]

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


    struct neword
    {
        string element;
        int tick;
    };
    neword temp;
int main(int argc, char *argv[])
{
    //  This is a list of the most common words. they will not be included in the parsed list
    string banlist[50]{"the","be","to","of","and","a","in","that","have","i","it","for","not","on","with","he","as","you","do",
    "at","this","but","his","by","from","they","we","say","her","she","or","an","will","my","one","all","would","there","their",
    "what","so","up","out","if","about","who","get","which","go","me"};

    int mainleng = 100; //  length for unique word array
    neword * elemarray = new neword[mainleng];  //  create an array of values to store all unique non-banned words
    int maindex = 0;    //  main iterator, also functions as the total word counter
    int dubtick = 0;
    int totick = 0;
    string maxel;

    //int argtemp = int argv[2];

    bool isbanned = false;
    bool isfound = true;

    int maxundex = 1;   //  iterator for size of unique word array
    string * unarray = new string[maxundex];    //  create an array for unique, unbanned words
    unarray[0] = "intler";  //  provide an initial value in the array of unique words to begin comparing against

    ifstream filein;    //  declare the variable of the file
    string element;     // declare the variable of read in strings
    filein.open(argv[1]);

    //filein.open("testfile.txt");


    while(filein >> element)    //  begin reading in each word as "element"
    {
        //totick++;
        isbanned = false;   // initialize each new word in element as unbanned and unfound
        isfound = false;

        for(int i = 0; i < 50; i++) //  REMOVES BANNED WORDS    //  banned word forloop iterates to 50 (number of banned words)
        {
            if(element == banlist[i])   //  if the element matches a word in the banned word list
            {
                isbanned = true;    //  set boolean isbanned to true
            }
        }
        if(isbanned == false)   //  ADDS TICKS TO WORDS ALREADY IN ARRAY   //  if the the current word in variable [element] is not banned
        {
            totick++;
            for(int a = 0; a < maindex; a++)    //  starting from zero and ending at the current length of the index
            {
                if(elemarray[a].element == element)     //  if the element is already in the array
                {
                    elemarray[a].tick++;    //  increment the counter struct [tick] for that member of element
                    isfound = true;
                }
            }
            if(isfound == false)    //  DOUBLES SIZE OF ARRAY WHEN ARRAY IS FULL    //  if the current word in [element] is not in the array
            {
                if(maindex == mainleng)     //  if the main indexing variable [maindex] is at the end of its array length [mainleng]
                {
                    mainleng = mainleng*2;  //  double the length of the array
                    dubtick++;

                    neword * p2;
                    p2 = new neword[mainleng];
                    for(int x = 0; x < mainleng/2; x++)
                    {
                        p2[x] = elemarray[x];
                    }
                        delete []elemarray;
                        elemarray = p2;

                }
            elemarray[maindex].element = element;
            elemarray[maindex].tick++;

            //cout<<elemarray[maindex].element<<endl;
            //cout<<elemarray[maindex].tick<<endl;



            maindex++;
            }   //  end of array doubler
        }   //  end of tick adder
    }   //  end of while

        for(int b = 0; b < maindex; b++)
        {
            for(int u = 0; u < maindex; u++)
            {
                if(elemarray[b].tick > elemarray[u].tick)
                {
                temp = elemarray[b];
                elemarray[b] = elemarray[u];
                elemarray[u] = temp;
                }
            }
        }
        for(int g = 0; g < atoi(argv[2]); g++)
        {
            cout<<elemarray[g].tick<<" - "<<elemarray[g].element<<endl;
        }

    cout<<"#"<<endl;
    cout<<"Array doubled: "<<dubtick<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<maindex<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<totick<<endl;
}   //  end of void


