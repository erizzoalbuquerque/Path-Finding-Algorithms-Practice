#pragma once

#include <vector>
#include "maze.hpp"
#include "cell.hpp"

namespace maze
{
    class MazeRenderer
    {
    public:
        MazeRenderer(const Maze& maze)
            : maze_(maze)
        {

        }

        ~MazeRenderer() = default;

        void render() const;
        //void set_path(const std::vector<int>& path);
    
    private:
        const Maze& maze_;
        //std::vector<int> path_;        
    };
}