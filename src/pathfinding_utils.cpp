#include "../include/pathfinding_utils.hpp"
#include <deque>

namespace pathfinding
{
    std::vector<int> reconstruct_path(int source, int target, const std::vector<int>& predecessors)
    {
        std::deque<int> shortest_path;

        shortest_path.push_back(target);
        int curr = target;    
        while (curr != source)
        {
            int next = predecessors[curr];

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