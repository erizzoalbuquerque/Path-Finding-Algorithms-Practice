#include "../include/a_star.hpp"
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

std::vector<int> a_star(const Graph& graph, int source, int target, std::function<float(int,int)> heuristic)
{
    //assert source and target are valid
    assert(source >= 0 && source < graph.num_vertices());
    assert(target >= 0 && target < graph.num_vertices());

    // if target == source, we already have the best path
    if (source == target)
    {
        return {source};
    }
    
    // init dist as inf, except for source
    std::vector<float> dist(graph.num_vertices(), std::numeric_limits<float>::max());
    dist[source] = 0;

    // visited nodes set to false
    std::vector<bool> visited(graph.num_vertices(), false);

    // best predecessor for each node
    std::vector<int> predecessor(graph.num_vertices(), -1);

    // priority queue (distance,node) with smaller distance on top
    std::priority_queue<
        std::pair<float,int>,
        std::vector<std::pair<float,int>>,
        std::greater<std::pair<float,int>>
        > pq;
    pq.push({0.f,source});

    while (!pq.empty())
    {
        int exploring_node = pq.top().second;

        pq.pop(); //remove top from queue

        if (exploring_node == target)
        {
            break;
        }

        // if we already explored this node, there's no need to explore again
        if (visited[exploring_node])
        {
            continue;
        }

        const std::vector<Graph::Neighbor>& neighbors = graph.neighbors(exploring_node);
        
        float current_distance = dist[exploring_node];
        
        for (const auto&[next_node,edge_weight] : neighbors)
        {
            float new_distance = current_distance + edge_weight;

            if (new_distance < dist[next_node])
            {
                //update distance to next node
                dist[next_node] = new_distance;
                
                //update predecessor
                predecessor[next_node] = exploring_node;

                //insert node in the exploring queue
                pq.push({new_distance + heuristic(next_node, target), next_node});
            }            
        }

        // mark node as visited
        visited[exploring_node] = true;
    }

    return create_shortest_path_vector(source, target, predecessor);
}