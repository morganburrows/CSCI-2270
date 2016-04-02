#include "MovieTree.h"

MovieTree::MovieTree()
{
    root = NULL;
}
MovieTree::~MovieTree()
{
    //dtor
}

MovieNode* MovieTree::search(std::string title)
{
    MovieNode * Fnode = new MovieNode;
    Fnode = root;

    while(Fnode != NULL)
    {
        if(title.compare(Fnode->title) < 0)
        {
            Fnode = Fnode->leftChild;
        }
        else if(title.compare(Fnode->title) > 0)
        {
            Fnode = Fnode->rightChild;
        }
        else if(title.compare(Fnode->title) == 0)
        {
            break;
        }
    }

    return Fnode;
}


void MovieTree::findMovie(std::string inmov)
{
    MovieNode *Fnode = search(inmov);

    if(Fnode == NULL)
    {
        cout<<"Movie not found."<<endl;
        return;
    }

    cout << "Movie Info:" << endl;
    cout << "===========" << endl;
    cout << "Ranking:" << Fnode->ranking << endl;
    cout << "Title:" << Fnode->title << endl;
    cout << "Year:" << Fnode->year << endl;
    cout << "Quantity:" << Fnode->quantity << endl;
}

void MovieTree::rentMovie(std::string rinmov)
{
    MovieNode *Rnode = search(rinmov);

    if(Rnode == NULL)
    {
        cout<<"Movie not found."<<endl;
        return;
    }

    if(Rnode->quantity <= 0)
    {
        cout << "Movie out of stock." << endl;
        return;
    }

    Rnode->quantity = Rnode->quantity - 1;

    cout << "Movie has been rented." << endl;
    cout << "Movie Info:" << endl;
    cout << "===========" << endl;
    cout << "Ranking:" << Rnode->ranking << endl;
    cout << "Title:" << Rnode->title << endl;
    cout << "Year:" << Rnode->year << endl;
    cout << "Quantity:" << Rnode->quantity << endl;
}

void MovieTree::addMovieNode(int movrank, std::string movtitle, int movyear, int movquant)
{
    MovieNode *innode = new MovieNode(movrank, movtitle, movyear, movquant);
    innode->parent = NULL;
    innode->leftChild = NULL;
    innode->rightChild = NULL;
    if(root == NULL)
    {
        root = innode;
    }
    else
    {
        MovieNode *temp = root;
        while(temp != NULL)
        {
            if(movtitle.compare(temp->title) < 0)
            {
                if(temp->leftChild != NULL)
                {
                    temp = temp->leftChild;
                }
                else
                {
                    temp->leftChild = innode;
                    innode->parent = temp;
                    temp = NULL;
                }
            }
            else
            {
                if(temp->rightChild != NULL)
                {
                    temp = temp->rightChild;
                }
                else
                {
                    temp->rightChild = innode;
                    innode->parent = temp;
                    temp = NULL;
                }
            }
        }
    }
}

void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}

void MovieTree::printMovieInventory(MovieNode *node)
{
    if(node->leftChild != NULL)
    {
        printMovieInventory(node->leftChild);
    }
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    if(node->rightChild != NULL)
    {
        printMovieInventory(node->rightChild);
    }
}
