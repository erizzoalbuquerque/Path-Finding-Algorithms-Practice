#pragma once

#include <vector>
#include "cell.hpp"

namespace maze
{
    class Maze
    {
    public:
        Maze(int width, int height) :
            width_(width), height_(height), matrix_(height, std::vector<Cell>(width, Cell::Wall) )
        {
        }

        ~Maze() = default;

        int width() const { return width_; }
        int height() const { return height_; }
        Cell cell(int x, int y) const; 
        void set_cell(int x, int y, Cell cell_type);
        
    private:
        int width_;
        int height_;
        std::vector< std::vector<Cell> > matrix_;
    };
}