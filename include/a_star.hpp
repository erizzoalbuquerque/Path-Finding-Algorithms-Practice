#pragma once

#include "../include/graph.hpp"
#include <vector>
#include <functional>

namespace pathfinding
{
    std::vector<int> a_star(const Graph& graph, int source, int target, std::function<float(int,int)> heuristic);
}