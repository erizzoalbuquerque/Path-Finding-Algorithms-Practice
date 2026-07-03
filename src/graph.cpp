#include "../include/graph.hpp"
#include <cassert>
#include <iostream>

namespace pathfinding
{
    Graph::Graph(int num_vertices) : num_vertices_(num_vertices), adj_list_(num_vertices)
    {
    }

    void Graph::add_edge(int u, int v,float weight, bool directed)
    {
        assert(u >= 0 && u < num_vertices_);

        adj_list_[u].emplace_back(v, weight);
        
        if (!directed)
        {
            adj_list_[v].emplace_back(u,weight);
        }
    }

    const std::vector<Graph::Neighbor>& Graph::neighbors(int u) const
    {
        return adj_list_.at(u);
    }

    int Graph::num_vertices() const
    {
        return num_vertices_;
    }

    void Graph::print_neighbors(int node) const
    {
        assert(node >= 0 && node < num_vertices_);

        std::cout << "Neighbors of node " << node << ": ";
        for (const auto& neighbor : adj_list_[node])
        {
            std::cout << "(" << neighbor.first << ", weight: " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
}