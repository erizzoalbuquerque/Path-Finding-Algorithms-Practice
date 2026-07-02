#pragma once
#include <vector>

namespace pathfinding
{
    std::vector<int> reconstruct_path(int source, int target, const std::vector<int>& predecessor);

    void print_path(const std::vector<int>& path);
}