#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    int ID;
    std::string name;
    int district;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
};

struct queueVertex
{
    int distance;
    std::vector<vertex *> path;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        void assignDistricts();
        void BFTraversalLabel(std::string startingCity, int distID);
        void shortestPath(std::string startingCity,std::string endingCity);
        vertex * findVertex(std::string name);

    protected:
    private:
        std::vector<vertex> vertices;

};

#endif // GRAPH_H
