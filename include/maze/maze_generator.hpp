#pragma once

#include "maze.hpp"

namespace maze
{
    class MazeGenerator
    {
    public:
        MazeGenerator(int width, int height)
            : width_(width), height_(height)
        {
        }

        virtual ~MazeGenerator() = default;

        virtual Maze generate() const = 0;

    protected:
        int width_;
        int height_;
    };
}