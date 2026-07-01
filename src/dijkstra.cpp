#include "../include/dijkstra.hpp"
#include "../include/pathfinding_utils.hpp"
#include <queue>
#include <functional>
#include <limits>
#include <deque>
#include <cassert>

namespace pathfinding
{
    std::vector<int> dijkstra(const Graph& graph, int source, int target)
    {
        assert(source >= 0 && source < graph.num_vertices());
        assert(target >= 0 && target < graph.num_vertices());

        if (source == target)
        {
            return {source};
        }
        
        std::vector<float> dist(graph.num_vertices(), std::numeric_limits<float>::max());
        dist[source] = 0;

        std::vector<bool> visited(graph.num_vertices(), false);

        std::vector<int> predecessor(graph.num_vertices(), -1);

        std::priority_queue<
            std::pair<float,int>,
            std::vector<std::pair<float,int>>,
            std::greater<std::pair<float,int>>
            > pq;
        pq.push({0.f,source});

        while (!pq.empty())
        {
            std::pair<float,int> top = pq.top();

            //float current_distance = top.first;
            //int exploring_node = top.second; 
            auto [current_distance, exploring_node] = pq.top();

            pq.pop();

            if (exploring_node == target)
            {
                break;
            }

            if (visited[exploring_node])
            {
                continue;
            }

            const std::vector<Graph::Neighbor>& neighbors = graph.neighbors(exploring_node);
            
            //for (const auto& neighbor : neighbors)
            for (const auto&[next_node,edge_weight] : neighbors)
            {
                //int next_node = neighbor.first;
                //float edge_weight = neighbor.second;

                float new_distance = current_distance + edge_weight;
                if (new_distance < dist[next_node])
                {
                    dist[next_node] = new_distance;
                    pq.push({new_distance, next_node});
                    predecessor[next_node] = exploring_node;
                }            
            }

            visited[exploring_node] = true;
        }

        return reconstruct_path(source, target, predecessor);
    }
}