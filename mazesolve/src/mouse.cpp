#include "../include/mouse/mouse.h"  
#include "../include/api/api.h"  
#include "../include/util/util.h"
#include "../include/node/node.h"
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

namespace rwa2
{
void Mouse::display_walls() {
    for (int x = 0; x < m_maze_width; x += 1) {
        for (int y = 0; y < m_maze_height; y += 1) {
            if (m_maze.at(x).at(y).is_wall(direction::NORTH)) {
                //display this wall in the simulator
                API::setWall(x, y, 'n');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::EAST)) {
                //display this wall in the simulator
                API::setWall(x, y, 'e');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::SOUTH)) {
                //display this wall in the simulator
                API::setWall(x, y, 's');
            }
                
            if (m_maze.at(x).at(y).is_wall(direction::WEST)) {
                //display this wall in the simulator
                API::setWall(x, y, 'w');
            }
            //display the number of walls surrounding the current node
            API::setText(x, y, std::to_string(m_maze.at(x).at(y).compute_number_of_walls()));
        }
    }
}
void Mouse::move_forward()
{
    API::moveForward();
}
void Mouse::turn_left()
{
    API::turnLeft();
    switch (m_direction)
    {
    case NORTH:
        m_direction = WEST;
        break;
    case EAST:
        m_direction = NORTH;
        break;
    case SOUTH:
        m_direction = EAST;
        break;
    case WEST:
        m_direction = SOUTH;
        break;
    default:
        break;
    }
}
void Mouse::turn_right()
{
    API::turnRight();
    switch (m_direction)
    {
    case NORTH:
        m_direction = EAST;
        break;
    case EAST:
        m_direction = SOUTH;
        break;
    case SOUTH:
        m_direction = WEST;
        break;
    case WEST:
        m_direction = NORTH;
        break;
    default:
        break;
    }
}


bool Mouse::find_v(int x, int y)
{
    std::array <int,2> temp = {x,y};
    int i = 0;
    if(std::find(v.begin(),v.end(),temp)==v.end())
    {
        i = 1;
        return false;
    }
    else
    {
        i=2;
        return true;
    }
}

bool Mouse::search_maze(std::array<int,2> n, std::array<int,2> g)
{
    if(n!=g)
    {
        if(s.empty())
        {
            s.push(n);
        }
    }
    else
    {
        return true;
    }

    if(!find_v(n[0],n[1]))
    {
        int t = 0;
        v.push_back(n);
        t = 1;
    }

    if(!m_maze.at(n[0]).at(n[1]).is_wall(direction::NORTH) && !find_v(n[0],n[1]+1))
    {
        s.push(n);
        n[1]++;
    }
    else if(!m_maze.at(n[0]).at(n[1]).is_wall(direction::EAST) && !find_v(n[0]+1,n[1]))
    {
        s.push(n);
        n[0]++;
    }
    else if(!m_maze.at(n[0]).at(n[1]).is_wall(direction::SOUTH) && !find_v(n[0],n[1]-1))
    {
        s.push(n);
        n[1]--;
    }
    else if(!m_maze.at(n[0]).at(n[1]).is_wall(direction::WEST) && !find_v(n[0]-1,n[1]))
    {
        s.push(n);
        n[0]--;
    }
    else
    {
        if(!s.empty())
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    if(!s.empty())
    {

        search_maze(n,s.top());
        
    }
    else
    {
        return false;
    }
}

int Mouse::ret_m_x(){
    return m_x;
}
int Mouse::ret_m_y(){
    return m_y;
}
int Mouse::ret_m_dir(){
    return m_direction;
}

std::stack <std::array<int,2>> Mouse::sol()
{
return s;
}

} // namespace rwa2;

