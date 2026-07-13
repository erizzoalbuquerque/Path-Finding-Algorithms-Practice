#pragma once

#include "maze_generator.hpp"
#include "maze.hpp"

namespace maze
{
    class RecursiveBacktracker : public MazeGenerator
    {
    public:
        RecursiveBacktracker(int width, int height)
            : MazeGenerator(width, height)
        {

        }

        Maze generate() const override;
    };
}