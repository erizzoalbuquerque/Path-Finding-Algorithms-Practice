#include <iostream>
#include "../include/dijkstra.hpp"

int main()
{
    Graph graph(5);

    graph.add_edge(0,1,4,true);
    graph.add_edge(0,2,1,true);
    graph.add_edge(2,1,2,true);
    graph.add_edge(2,3,5,true);
    graph.add_edge(1,3,1,true);
    graph.add_edge(1,4,7,true);
    graph.add_edge(3,4,3,true);

    std::vector<int> best_path = dijkstra(graph,0,4);

    std::cout << "Best path is: " << std::endl;
    for (int i = 0; i < best_path.size(); i++)
    {
        if (i > 0)
            std::cout << ", ";
        std::cout << best_path[i]; 
    }
    std::cout << "." << std::endl;

    return 0;
}