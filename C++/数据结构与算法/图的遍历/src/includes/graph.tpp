#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
Graph<T>::Graph() {}

template <class T>
Graph<T>::~Graph() {
    for (size_t i = 0; i < adj.size(); ++i) {
        adjacency<T>* current = adj[i];
        while (current != nullptr) {
            adjacency<T>* next = current->next;
            delete current;
            current = next;
        }
    }
}

template <class T>
int Graph<T>::addVertex(T val) {
    vertex<T> newVertex;
    newVertex.data = val;
    newVertex.visited = false;
    
    vertices.push_back(newVertex);
    adj.push_back(nullptr);
    
    return vertices.size() - 1;
}

template <class T>
void Graph<T>::addEdge(int u, int v) {
    int max_idx = std::max(u, v);
    
    if (max_idx >= vertices.size()) {
        int old_size = vertices.size();
        int new_size = max_idx + 1;
        for (int i = old_size; i < new_size; ++i) {
            addVertex(T()); 
        }
    }

    // u -> v
    adjacency<T>* node1 = new adjacency<T>;
    node1->index = v;
    node1->next = adj[u];
    adj[u] = node1;

    // v -> u
    adjacency<T>* node2 = new adjacency<T>;
    node2->index = u;
    node2->next = adj[v];
    adj[v] = node2;
}

template <class T>
void Graph<T>::build(std::vector<std::pair<int, int>> data) {
    for (auto& edge : data) {
        addEdge(edge.first, edge.second);
    }
}

template <class T>
void Graph<T>::print() {
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << "Vertex " << i << " (" << vertices[i].data << "):";
        adjacency<T>* ptr = adj[i];
        while (ptr) {
            std::cout << " -> " << ptr->index;
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
}

template <class T>
void Graph<T>::resetVisited() {
    for (auto& v : vertices) {
        v.visited = false;
    }
}

template <class T>
void Graph<T>::dfs(int start) {
    if (start < 0 || start >= vertices.size()) {
        std::cerr << "Error: Start vertex index out of bounds." << std::endl;
        return;
    }
    
    vertices[start].visited = true;
    std::cout << start << " ";

    adjacency<T>* p = adj[start];
    while (p) {
        int v = p->index;
        if (!vertices[v].visited) {
            dfs(v);
        }
        p = p->next;
    }
}

template <class T>
void Graph<T>::bfs(int start) {
    if (start < 0 || start >= vertices.size()) {
        std::cerr << "Error: Start vertex index out of bounds." << std::endl;
        return;
    }

    vertices[start].visited = true;
    std::cout << start << " ";

    std::vector<int> queue;
    queue.push_back(start);

    while (!queue.empty()) {
        int u = queue.front();
        queue.erase(queue.begin());

        adjacency<T>* p = adj[u];
        while (p) {
            int v = p->index;
            if (!vertices[v].visited) {
                vertices[v].visited = true;
                std::cout << v << " ";
                queue.push_back(v);
            }
            p = p->next;
        }
    }
}
