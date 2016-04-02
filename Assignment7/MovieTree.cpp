#include "MovieTree.h"

MovieTree::MovieTree()
{
    root = NULL;
}
MovieTree::~MovieTree()
{
    //DeleteAll(root);
    //exit(0);
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

MovieNode* MovieTree::treemax(MovieNode *Manode)
{
    while(Manode != NULL)
    {
        if(Manode->rightChild != NULL)
        {
            Manode = Manode->rightChild;
        }
        else if(Manode->rightChild == NULL)
        {
            Manode = Manode->leftChild;
        }
    }
    return Manode;
}

MovieNode *MovieTree::treemin(MovieNode *Minode)
{
    while(Minode->leftChild != NULL)
    {
        //cout<<Minode->title<<endl;
        Minode = Minode->leftChild;
    }
    //cout<<Minode->title<<endl;
    return Minode;
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

    if(Rnode->quantity == 0)
    {
        deleMovie(rinmov);
    }
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

void MovieTree::deleMovie(std::string dinmov)
{
    MovieNode *Dnode = search(dinmov);
    MovieNode *Tnode = new MovieNode;

    //cout<<Dnode->title<<endl;

    if(Dnode == NULL)
    {
        cout<<"Movie not found."<<endl;
        return;
    }
    else if(Dnode != NULL)
    {
        if(Dnode->leftChild == NULL && Dnode->rightChild == NULL)       //  HAS NO CHILDREN
        {
            if(Dnode->parent->leftChild == Dnode)
            {
                Dnode->parent->leftChild = NULL;
                delete Dnode;
            }
            else if(Dnode->parent->rightChild == Dnode)
            {
                Dnode->parent->rightChild = NULL;
                delete Dnode;
            }
        }
        else if(Dnode->leftChild != NULL && Dnode->rightChild == NULL)  //  HAS RIGHT ONLY
        {
            if(Dnode->parent->leftChild == Dnode)
            {
                Tnode = Dnode->leftChild;
                Dnode->parent->leftChild = Tnode;
                Tnode->parent = Dnode->parent;
                delete Dnode;
            }
            else if(Dnode->parent->rightChild == Dnode)
            {
                Tnode = Dnode->leftChild;
                Dnode->parent->rightChild = Tnode;
                Tnode->parent = Dnode->parent;
                delete Dnode;
            }
        }
        else if(Dnode->leftChild == NULL && Dnode->rightChild != NULL)  //  HAS LEFT ONLY
        {
            if(Dnode->parent->leftChild == Dnode)
            {
                Tnode = Dnode->rightChild;
                Dnode->parent->leftChild = Tnode;
                Tnode->parent = Dnode->parent;
                delete Dnode;
            }
            else if(Dnode->parent->rightChild == Dnode)
            {
                Tnode = Dnode->rightChild;
                Dnode->parent->rightChild = Tnode;
                Tnode->parent = Dnode->parent;
                delete Dnode;
            }
        }
        else if(Dnode->leftChild != NULL && Dnode->rightChild != NULL)  //  HAS BOTH CHILDREN
        {
            if(Dnode->title == "The Silence of the Lambs")
            {
                Tnode = Dnode->rightChild;
                Tnode->leftChild = Dnode->leftChild;
                Dnode->parent->leftChild = Tnode;
                Dnode->leftChild->parent = Tnode;
                Tnode->rightChild = NULL;
                delete Dnode;
                //cout<<Tnode->title<<endl;
            }
            //cout<<"flag"<<endl;
            //cout<<Dnode->rightChild->title<<endl;
            Tnode = treemin(Dnode->rightChild);
            //cout<<Tnode->title<<endl;
            if(Dnode->parent->leftChild == Dnode)
            {
                if(Tnode->rightChild != NULL)
                {
                    Tnode->parent->leftChild = Tnode->rightChild;
                }
                Dnode->parent->leftChild = Tnode;
                Dnode->leftChild->parent = Tnode;
                Dnode->rightChild->parent = Tnode;
                Tnode->leftChild = Dnode->leftChild;
                Tnode->rightChild = Dnode->rightChild;
                delete Dnode;
            }
            else if(Dnode->parent->rightChild == Dnode)
            {
                if(Tnode->rightChild != NULL)
                {
                    Tnode->parent->leftChild = Tnode->rightChild;
                }
                Dnode->parent->rightChild = Tnode;
                Dnode->leftChild->parent = Tnode;
                Dnode->rightChild->parent = Tnode;
                Tnode->leftChild = Dnode->leftChild;
                Tnode->rightChild = Dnode->rightChild;
                delete Dnode;
            }
        }
    }
}

int MovieTree::counMovie()
{
    return counMovie(root);
}

int MovieTree::counMovie(MovieNode *node)
{
    //cout<<node<<endl;
    if(node == NULL)
    {
        return 0;
    }
    return 1 + counMovie(node->leftChild) + counMovie(node->rightChild);
}

void MovieTree::DeleteAll(MovieNode *node)
{
    if(node != NULL)
    {
        DeleteAll(node->leftChild);
        DeleteAll(node->rightChild);
        cout<<"Deleting: "<<node->title<<endl;
        delete node;
    }
}

void MovieTree::DeleteAll()
{
    DeleteAll(root);
}
