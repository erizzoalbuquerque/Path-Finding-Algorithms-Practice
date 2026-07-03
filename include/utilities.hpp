#pragma once

#include "graph.hpp"
#include "vec2.hpp"

inline void add_edges_from_position(int first, int second, pathfinding::Graph& graph, const std::vector<math::Vec2>& positions, bool directed = false)
{
    graph.add_edge(first, second, math::Vec2::distance(positions[first], positions[second]), directed);
}