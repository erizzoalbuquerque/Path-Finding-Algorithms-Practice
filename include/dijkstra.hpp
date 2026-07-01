#pragma once

#include "../include/graph.hpp"
#include <vector>

namespace pathfinding
{
    std::vector<int> dijkstra(const Graph& graph, int source, int target);
}