#include "Graph.h"

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}

void Graph::addEdge(std::string v1, std::string v2, int weight)
{
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(unsigned int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(std::string n)
{
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i].name<<"-->";

        for(unsigned int j = 0; j < vertices[i].adj.size(); j++)
        {
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }
}

void Graph::assignDistricts()
{

}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{

}

void Graph::shortestPath(std::string startingCity,std::string endingCity)
{

}

