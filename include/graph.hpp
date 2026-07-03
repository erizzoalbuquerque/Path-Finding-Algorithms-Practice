#pragma once

#include <vector>

namespace pathfinding
{
    class Graph 
    {
    public:
        using Neighbor = std::pair<int,float>; // (node, weight)  
        Graph(int num_vertices);
        ~Graph() = default;
        void add_edge(int u, int v, float weight, bool directed = false);
        const std::vector<Neighbor>& neighbors(int u) const;
        int num_vertices() const;
        void print_neighbors(int node) const;

    private:
        int num_vertices_;
        std::vector<std::vector<Neighbor>> adj_list_;
    };
}