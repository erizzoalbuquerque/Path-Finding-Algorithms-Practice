#include "../include/graph.hpp"
#include <cassert>

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