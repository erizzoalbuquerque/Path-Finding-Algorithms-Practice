#include <iostream>
#include "../../include/maze/maze_renderer.hpp"

namespace maze
{
    void MazeRenderer::render() const
    {
        for (int y = maze_.height()-1; y >= 0; --y)
        {
            for (int x = 0; x < maze_.width(); ++x)
            {
                switch (maze_.cell(x, y))
                {
                    case Cell::Path:
                        std::cout << ".";
                        break;
                    case Cell::Wall:
                        std::cout << "#";
                        break;
                    default:
                        std::cout << "?";
                        break;
                }
            }

            std::cout<< '\n';
        }              
    }
}