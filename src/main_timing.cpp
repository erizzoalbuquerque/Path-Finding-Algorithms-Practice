#include "../include/a_star.hpp"
#include "../include/dijkstra.hpp"
#include "../include/graph.hpp"
#include "../include/vec2.hpp"
#include "../include/pathfinding_utils.hpp"
#include <vector>
#include <iostream>
#include "../include/utilities.hpp"
#include "../include/timer.hpp"

using namespace pathfinding;
using namespace math;

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

    auto distance_heuristic = [&positions](int nodeA, int nodeB){
        return Vec2::distance(positions[nodeA],positions[nodeB]);
    };

    Timer timer1;
    std::vector<int> best_path_dijkstra = dijkstra(graph, 0, 6);
    std::cout << "Dijkstra algorithm took " << timer1.elapsed() << " seconds" << std::endl;

    Timer timer2;
    std::vector<int> best_path = a_star(graph, 0, 6, distance_heuristic);
    std::cout << "A* algorithm took " << timer2.elapsed() << " seconds." << std::endl;
    
    return 0;
}