#include "../include/maze/maze.hpp"
#include "../include/maze/maze_renderer.hpp"
#include "../include/maze/recursive_backtracker.hpp"

int main()
{
    maze::RecursiveBacktracker generator(3, 3);
    maze::Maze maze = generator.generate();

    maze::MazeRenderer maze_renderer(maze);
    maze_renderer.render();

    return 0;
}