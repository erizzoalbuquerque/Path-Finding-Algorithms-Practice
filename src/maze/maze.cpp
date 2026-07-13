#include <cassert>
#include "../../include/maze/cell.hpp"
#include "../../include/maze/maze.hpp"

namespace maze
{
    Cell Maze::cell(int x, int y) const
    {
        assert( x >= 0 && x < width_ && y >= 0 && y < height_);

        return matrix_[y][x];
    }

    void Maze::set_cell(int x, int y, Cell cell_type)
    {
       assert( x >= 0 && x < width_ && y >= 0 && y < height_);
       
       matrix_[y][x] = cell_type;
    }
}