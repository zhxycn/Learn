#include "includes/graph.h"
#include <iostream>
#include <string>
#include <limits>

int main() {
    Graph<std::string> g;

    std::cout << "Please input edges (u v), input # to end:" << std::endl;
    int u, v;
    while (true) {
        std::cin >> std::ws;
        if (std::cin.peek() == '#') {
            std::cin.ignore();
            break;
        }
        
        if (!(std::cin >> u >> v)) {
            break;
        }
        g.addEdge(u, v);
    }

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    g.print();

    std::cout << "Please input start vertex: ";
    int start;
    std::cin >> start;

    g.dfs(start);
    std::cout << std::endl;
    g.resetVisited();
    g.bfs(start);
    std::cout << std::endl;

    return 0;
}
