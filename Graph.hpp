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

    void addNode(const char* name, float x, float y) {
        if (numNodes >= MAX_NODES) return; 
        Node& n = nodes[numNodes];
        strncpy(n.name, name, sizeof(n.name) - 1);
        n.name[sizeof(n.name) - 1] = '\0'; 
        n.x = x;
        n.y = y;
        numNodes++;
    }
    
    void addEdge(int from, int to, float weight) {
        if (from < 0 || from >= numNodes || to < 0 || to >= numNodes) return; 
        Edge* newEdge = new Edge{to, weight, adjacency[from]};
        adjacency[from] = newEdge;
        
        Edge* rev = new Edge{from, weight, adjacency[to]};
        adjacency[to] = rev;
    }
};

#endif