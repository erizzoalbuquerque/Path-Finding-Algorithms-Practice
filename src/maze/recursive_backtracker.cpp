#include "../include/maze/recursive_backtracker.hpp"
#include "../include/maze/maze.hpp"
#include "../include/maze/cell.hpp"
#include <stack>
#include <vector>
#include <algorithm>
#include <random>

namespace maze
{
    Maze RecursiveBacktracker::generate() const
    {
        int maze_width = width_ * 2 - 1;
        int maze_height = height_ * 2 - 1;
        Maze maze(maze_width, maze_height);

        // open all cell positions (even indices)
        for (int y = 0; y < height_; ++y)
            for (int x = 0; x < width_; ++x)
                maze.set_cell(x * 2, y * 2, Cell::Path);

        // DFS with stack
        std::stack<std::pair<int,int>> stack;
        std::vector<std::vector<bool>> visited(height_, std::vector<bool>(width_, false));

        std::random_device rd;
        std::mt19937 rng(rd());

        int start_x = 0, start_y = 0;
        stack.push({start_x, start_y});
        visited[start_y][start_x] = true;

        // directions: right, left, down, up
        std::vector<std::pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!stack.empty())
        {
            auto [cx, cy] = stack.top();

            // find unvisited neighbors
            std::vector<std::pair<int,int>> neighbors;
            for (auto [dx, dy] : directions)
            {
                int nx = cx + dx;
                int ny = cy + dy;
                if (nx >= 0 && nx < width_ && ny >= 0 && ny < height_ && !visited[ny][nx])
                    neighbors.push_back({nx, ny});
            }

            if (!neighbors.empty())
            {
                // pick random neighbor
                std::uniform_int_distribution<int> dist(0, neighbors.size() - 1);
                auto [nx, ny] = neighbors[dist(rng)];

                // open wall between current and neighbor
                int wall_x = cx * 2 + (nx - cx);
                int wall_y = cy * 2 + (ny - cy);
                maze.set_cell(wall_x, wall_y, Cell::Path);

                visited[ny][nx] = true;
                stack.push({nx, ny});
            }
            else
            {
                stack.pop();
            }
        }

        return maze;
    }
}