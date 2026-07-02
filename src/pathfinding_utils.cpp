#include "../include/pathfinding_utils.hpp"
#include <deque>
#include <iostream>

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

    void print_path(const std::vector<int>& path)
    {
        if (path.empty())
        {
            std::cout << "No path to print." << std::endl;
            return;
        }

        std::cout << "Best path is: " << std::endl;
        for(int i=0; i <path.size() ; i++)
        {
            if (i > 0) std::cout <<",";

            std::cout << path[i];
        }
        std::cout << "." << std::endl;
    }
}