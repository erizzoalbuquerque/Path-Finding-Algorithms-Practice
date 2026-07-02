#include <iostream>
#include "../include/dijkstra.hpp"
#include "../include/pathfinding_utils.hpp"

int main()
{
    using namespace pathfinding;
    
    Graph graph(5);

    graph.add_edge(0,1,4,true);
    graph.add_edge(0,2,1,true);
    graph.add_edge(2,1,2,true);
    graph.add_edge(2,3,5,true);
    graph.add_edge(1,3,1,true);
    graph.add_edge(1,4,7,true);
    graph.add_edge(3,4,3,true);

    std::vector<int> best_path = dijkstra(graph,0,4);

    print_path(best_path);

    return 0;
}