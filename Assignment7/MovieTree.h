#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>

using namespace std;

struct MovieNode
{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *parent = NULL;
    MovieNode *leftChild = NULL;
    MovieNode *rightChild = NULL;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    }

};

class MovieTree
{
    public:
        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void deleMovie(std::string title);
        int counMovie();
        void DeleteAll();



    protected:
    private:
        void DeleteAll(MovieNode * node);
        int counMovie(MovieNode * node);
        void printMovieInventory(MovieNode * node);
        MovieNode* search(std::string title);
        MovieNode *root;
        MovieNode *treemax(MovieNode *node);
        MovieNode *treemin(MovieNode *node);

};

#endif // MOVIETREE_H
