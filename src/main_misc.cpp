#include "../include/graph.hpp"
#include "../include/vec2.hpp"
#include "../include/pathfinding_utils.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace pathfinding;
using namespace math;

void add_edges_from_position(int first, int second, Graph& graph, const std::vector<Vec2>& positions)
{
    graph.add_edge(first, second, Vec2::distance(positions[first], positions[second]));
}

float get_path_length(const std::vector<int>& path, const Graph& graph)
{
    float length = 0.f;

    for (std::size_t i=0; i < path.size(); ++i)
    {
        if (i == path.size() -1)
            break;
            
        int current_node = path[i];
        int next_node = path[i+1];

        const auto& neighbors = graph.neighbors(current_node);
        
        auto it = std::find_if(neighbors.begin(),neighbors.end(),[next_node](const Graph::Neighbor& neighbor){
            return neighbor.first == next_node;
        });

        if (it != neighbors.end())
        {
            length += it->second;
        }
        else
        {
            return -1.f; // No path. Return error value
        }
    }

    return length;
}

int main()
{
    // Create map
    std::vector<Vec2> positions {
        {2.f, 7.f}, //A
        {4.f, 6.f}, //B
        {-2.f, 8.f}, //C
        {-9.f, 3.f}, //D
        {6.f, -1.f}, //E
        {-5.f, 3.f}, //F
        {10.f, 1.f} //G
    };    
    
    Graph graph(7);

    add_edges_from_position(0, 1, graph, positions); //A-B
    add_edges_from_position(0, 2, graph, positions); //A-C
    add_edges_from_position(0, 5, graph, positions); //A-F
    add_edges_from_position(1, 3, graph, positions); //B-D
    add_edges_from_position(1, 4, graph, positions); //B-E
    add_edges_from_position(3, 4, graph, positions); //D-E
    add_edges_from_position(4, 5, graph, positions); //E-F
    add_edges_from_position(4, 6, graph, positions); //E-G
    add_edges_from_position(5, 6, graph, positions); //F-G

    //print neighbors of each node
    for (int i = 0; i < graph.num_vertices(); i++)
    {
        graph.print_neighbors(i);
    }

    std::cout << "Path length (0->1->4->6): " << get_path_length({0,1,4,6}, graph) << std::endl;
    std::cout << "Path length (0->5->6): " << get_path_length({0,5,6}, graph) << std::endl;
    std::cout << "Path length (0->1->3->4->6): " << get_path_length({0,1,3,4,6}, graph) << std::endl;

    return 0;
}