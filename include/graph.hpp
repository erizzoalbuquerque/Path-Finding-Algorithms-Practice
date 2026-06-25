#pragma once

#include <vector>

class Graph 
{
public:
    using Neighbor = std::pair<int,int>; // Represents a neighbor vertex and the weight of the edge
    
    Graph(int num_vertices);
    ~Graph() = default;
    void add_edge(int u, int v, int weight, bool directed = false);
    const std::vector<Neighbor>& neighbors(int u) const;
    int num_vertices() const;

private:
    int num_vertices_;
    std::vector<std::vector<Neighbor>> adj_list_;
};