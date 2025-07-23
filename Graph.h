#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <cstring>
#include <cmath>

#define MAX_NODES 100
#define INF 1e9

struct Node {
    char name[50];
    float x, y;
};

struct Edge {
    int to;
    float weight;
    Edge* next;
};

class Graph {
    Node nodes[MAX_NODES];
    Edge* adjacency[MAX_NODES];
    int numNodes;
    
    Graph() {
        numNodes = 0;
        for (int i = 0; i < MAX_NODES; i++)
            adjacency[i] = nullptr;
    }
};

#endif