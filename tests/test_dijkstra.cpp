#include <gtest/gtest.h>
#include "../include/dijkstra.hpp"

using namespace pathfinding;

TEST(DijkstraTest, BasicPath)
{
    Graph graph(5);
    graph.add_edge(0,1,4.f,true);
    graph.add_edge(0,2,1.f,true);
    graph.add_edge(2,1,2.f,true);
    graph.add_edge(2,3,5.f,true);
    graph.add_edge(1,3,1.f,true);
    graph.add_edge(1,4,7.f,true);
    graph.add_edge(3,4,3,true);

    std::vector<int> expected = {0, 2, 1, 3, 4};
    std::vector<int> result = dijkstra(graph, 0, 4);

    EXPECT_EQ(result, expected);
}

TEST(DijkstraTest, SourceEqualsTarget)
{
    Graph graph(5);
    graph.add_edge(0,1,4.f,true);
    graph.add_edge(0,2,1.f,true);
    graph.add_edge(2,1,2.f,true);
    graph.add_edge(2,3,5.f,true);
    graph.add_edge(1,3,1.f,true);
    graph.add_edge(1,4,7.f,true);
    graph.add_edge(3,4,3.f,true);

    std::vector<int> expected = {0};
    std::vector<int> result = dijkstra(graph,0,0);

    EXPECT_EQ(result, expected);
}

TEST(DijkstraTest, UnreachableTarget)
{
    Graph graph(6);
    graph.add_edge(0,1,4.f,true);
    graph.add_edge(0,2,1.f,true);
    graph.add_edge(2,1,2.f,true);
    graph.add_edge(2,3,5.f,true);
    graph.add_edge(1,3,1.f,true);
    graph.add_edge(1,4,7.f,true);
    graph.add_edge(3,4,3.f,true);

    std::vector<int> expected = {};
    std::vector<int> result = dijkstra(graph,0,5);

    EXPECT_EQ(result, expected);
}