#ifndef C_GRAPH_H
#define C_GRAPH_H
template <class T>
struct vertex {
    T data;
    bool visited;
};

template <class T>
struct adjacency {
    int index;
    adjacency<T>* next;
};

#include <vector>

template <class T>
class Graph {
protected:
    std::vector<vertex<T>> vertices;
    std::vector<adjacency<T>*> adj;

public:
    Graph();
    ~Graph();
    int addVertex(T val);
    void addEdge(int u, int v);
    void build(std::vector<std::pair<int, int>> data);
    void print();
    void resetVisited();
    void dfs(int start);
    void bfs(int start);
};

#include "graph.tpp"

# endif // C_GRAPH_H