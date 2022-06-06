#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class Vertex;

class Edge{
private:
    Vertex* destination;
    int weight;
    Edge* nextEdge;
public:
    friend class Vertex;
    friend class DynamicGraph;
    Edge(Vertex* destination, int weight);
    string toString();
    Edge* get_nextEdge();
    Vertex* get_destination();
    string recuperacadena();
    char recuperades();

};

class Vertex{
private:
    char data;
    Vertex* nextVertex;
    Edge* firstEdge;
    int EdgesCount;
public:
    friend class Edge;
    friend class DynamicGraph;
    Vertex(char data);
    void addEdge(Vertex* edge, int weight);
    string toString();
    void removeEdge(Vertex* v_e);
    Edge* findEdge(Vertex* v_e);
    Edge* previousEdge(Edge* e);
    Vertex *get_siguiente();
    char get_data();
    int get_EdgesCount();
    Edge* get_firtsEdge();
};


class DynamicGraph
{
private:
	char actual;
	string visitados;
	char nombre;
    Vertex* firstVertex;
    int vertexCount;
public:

    DynamicGraph(char);
    //DynamicGraph(string);
    void addVertex(char data);
    void addEdge(char data_1, char data_2, int weight);
    string toString();
    string toString2();
    Vertex* findVertex(char data);
    void removeVertex(char e);
    Vertex* previousVertex(Vertex* v);
    void removeEdge(char data_1, char data_2);
    int getVertexCount() const;
    char& getVertexAt(int index);
    bool existEdge(char data_1, char data_2);
    int getWeightEdge(char data_1, char data_2);
    void addEdge2(char data_1, char data_2, int weight);
    string toFile();
    void load();
    char get_nombre();
    void set_visitados(string visi_);
    void set_actual(char);
    char get_actual();
    string lugares_adyacentes();
    void despalzarse(char);
    
};

/*
class StaticGraph{
private:
//    int** weight;
//    bool** edges;
//    char* dictionary;
    int weight[10][10];
    bool edges[10][10];
    char dictionary[10];
    int vertexCount;
public:
    StaticGraph(int vertexCount);
    StaticGraph();
    StaticGraph(DynamicGraph g);
    string toString();
    void save();
    void load();
    int getVertexCount() const;
    char& getVertexAt(int index);
    bool existEdge(char data_1, char data_2);
    int findVertex(char data);
    int getWeight(char data_1, char data_2);

};

*/
#endif // GRAPH_H

