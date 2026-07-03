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

    float Graph::get_path_length(const std::vector<int>& path) const
    {
        float length = 0.f;

        for (std::size_t i=0; i < path.size(); ++i)
        {
            if (i == path.size() -1)
                break;
                
            int current_node = path[i];
            int next_node = path[i+1];

            const auto& neighbors = this->neighbors(current_node);
            
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
}