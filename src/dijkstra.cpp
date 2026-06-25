#include "../include/dijkstra.hpp"
#include <queue>
#include <functional>
#include <limits>
#include <deque>
#include <cassert>

namespace
{
    std::vector<int> create_shortest_path_vector(int source, int target, const std::vector<int>& predecessor)
    {
        std::deque<int> shortest_path;

        shortest_path.push_back(target);
        int curr = target;    
        while (curr != source)
        {
            int next = predecessor[curr];

            if (next == -1)
            {
                return {};
            }

            shortest_path.push_front(next);
            curr = next;
        } 
        
        return std::vector<int>(shortest_path.begin(), shortest_path.end());
    }
}

std::vector<int> dijkstra(const Graph& graph, int source, int target)
{
    assert(source >= 0 && source < graph.num_vertices());
    assert(target >= 0 && target < graph.num_vertices());

    if (source == target)
    {
        return {source};
    }
    
    std::vector<int> dist(graph.num_vertices(), std::numeric_limits<int>::max());
    dist[source] = 0;

    std::vector<bool> visited(graph.num_vertices(), false);

    std::vector<int> predecessor(graph.num_vertices(), -1);

    std::priority_queue<
        std::pair<int,int>,
        std::vector<std::pair<int,int>>,
        std::greater<std::pair<int,int>>
        > pq;
    pq.push({0,source});

    while (!pq.empty())
    {
        std::pair<int,int> top = pq.top();

        //int current_distance = top.first;
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
            //int edge_weight = neighbor.second;

            int new_distance = current_distance + edge_weight;
            if (new_distance < dist[next_node])
            {
                dist[next_node] = new_distance;
                pq.push({new_distance, next_node});
                predecessor[next_node] = exploring_node;
            }            
        }

        visited[exploring_node] = true;
    }

    return create_shortest_path_vector(source, target, predecessor);
}