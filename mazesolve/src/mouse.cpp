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
void Mouse::wall_set(int x, int y)
{
    if(m_direction==0)
    {
        if(API::wallFront())
        {
            API::setWall(x,y,'n');
        }
        if(API::wallRight())
        {
            API::setWall(x,y,'e');
        }
        if(API::wallLeft())
        {
            API::setWall(x,y,'w');
        }
    }
    if(m_direction==1)
    {
        if(API::wallFront())
        {
            API::setWall(x,y,'e');
        }
        if(API::wallRight())
        {
            API::setWall(x,y,'s');
        }
        if(API::wallLeft())
        {
            API::setWall(x,y,'n');
        }
    }
    if(m_direction==2)
    {
        if(API::wallFront())
        {
            API::setWall(x,y,'s');
        }
        if(API::wallRight())
        {
            API::setWall(x,y,'w');
        }
        if(API::wallLeft())
        {
            API::setWall(x,y,'e');
        }
    }
    if(m_direction==3)
    {
        if(API::wallFront())
        {
            API::setWall(x,y,'w');
        }
        if(API::wallRight())
        {
            API::setWall(x,y,'n');
        }
        if(API::wallLeft())
        {
            API::setWall(x,y,'s');
        }
    }
}
bool Mouse::fnd_wall(int m_dir)
{   
    bool wall = false;
    if(m_direction==0)
    {
        switch (m_dir)
        {
        case 0:
            wall = API::wallFront();
            break;
        case 1:
            wall = API::wallRight();
            break;
        case 2:
            API::turnRight();
            wall = API::wallRight();
            API::turnLeft();
            break;
        case 3:
            wall = API::wallLeft();
            break;
        default:
            break;
        }
    }
    if(m_direction==1)
    {
        switch (m_dir)
        {
        case 0:
            wall = API::wallLeft();
            break;
        case 1:
            wall = API::wallFront();
            break;
        case 2:
            wall = API::wallRight();
            break;
        case 3:
            API::turnRight();
            wall = API::wallRight();
            API::turnLeft();
            break;
        default:
            break;
        }
    }
        if(m_direction==2)
    {
        switch (m_dir)
        {
        case 0:
            turn_right();
            wall = API::wallRight();
            turn_left();
            break;
        case 1:
            wall = API::wallLeft();
            break;
        case 2:
            wall = API::wallFront();
            break;
        case 3:
            wall = API::wallRight();
            break;
        default:
            break;
        }
    }
        if(m_direction==3)
    {
        switch (m_dir)
        {
        case 0:
            wall = API::wallRight();
            break;
        case 1:
            API::turnRight();
            wall = API::wallRight();
            API::turnLeft();
            break;
        case 2:
            wall = API::wallLeft();
            break;
        case 3:
            wall = API::wallFront();
            break;
        default:
            break;
        }
    }
    API::setColor(m_x,m_y,'w');
    std::cerr << "\n";
    return wall;
}
void Mouse::move_forward()
{
    API::moveForward(1);
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


void Mouse::motion(char xy)
{
    if(xy == 'u')
    {
        switch(m_direction)
        {
            case 0:
                move_forward();
                break;
            case 1:
                turn_left();
                move_forward();
                break;
            case 2:
                turn_left();
                turn_left();
                move_forward();
                break;
            case 3:
                turn_right();
                move_forward();
                break;
        }
    }
    if(xy == 'r')
    {
        switch(m_direction)
        {
            case 0:
                turn_right();
                move_forward();
                break;
            case 1:
                move_forward();
                break;
            case 2:
                turn_left();
                move_forward();
                break;
            case 3:
                turn_left();
                turn_left();
                move_forward();
            break;

        }
    }
    if(xy == 'd')
    {
        switch(m_direction)
        {
            case 1:
                turn_right();
                move_forward();
                break;
            case 2:
                move_forward();
                break;
            case 3:
                turn_left();
                move_forward();
                break;
            case 0:
                turn_left();
                turn_left();
                move_forward();
                break;
        }
    }
    if(xy == 'l')
    {
        switch(m_direction)
        {
            case 0:
                turn_left();
                move_forward();
                break;
            case 1:
                turn_right();
                turn_right();
                move_forward();
                break;
            case 2:
                turn_right();
                move_forward();
                break;
            case 3:
                move_forward();
                break;
        }
    }
}


bool Mouse::find_v(int x, int y)
{
    std::array <int,2> temp = {x,y};
    if(std::find(v.begin(),v.end(),temp)!=v.end())
    {
        return true;        //Visited
    }
    else
    {
        return false;       //Not visited
    }
}

bool Mouse::search_maze(std::array<int,2> n, std::array<int,2> g)
{
    wall_set(n[0],n[1]);
    std::cerr<<n[0]<<'\t'<<n[1]<<'\t';
    if(!(n[0]==g[0] && n[1]==g[1]))
    {
        if(s.empty())
        {
            s.push(n);
        }
    }
    else
    {
        std::cerr<<'\n'<<"Goal reached"<<'\n';
        return true;
    }

    if(!find_v(n[0],n[1]))
    {
        v.push_back(n);
    }
    
    if(!fnd_wall(NORTH) && !find_v(n[0],n[1]+1))
    {  
        API::setColor(n[0],n[1],'w');
        n[1]++;
        s.push(n);
        Mouse::motion('u');
    }
    else if(!fnd_wall(EAST) && !find_v(n[0]+1,n[1]))
    {
        API::setColor(n[0],n[1],'w');
        n[0]++;
        s.push(n);        
        Mouse::motion('r');
    }
    else if(!fnd_wall(SOUTH) && !find_v(n[0],n[1]-1))
    {
        API::setColor(n[0],n[1],'w');
        n[1]--;
        s.push(n);
        Mouse::motion('d');
    }
    else if(!fnd_wall(WEST) && !find_v(n[0]-1,n[1]))
    {
        API::setColor(n[0],n[1],'w');
        n[0]--;
        s.push(n);
        Mouse::motion('l');
    }
    else
    {
        if(!s.empty())
        {
            API::clearColor(n[0],n[1]);
            std::cerr<<"Bactrack"<<'\n';
            std::array<int,2> t2 = s.top();
            std::cerr<<'\n'<<t2[0]<<'\t'<<t2[1]<<'\n';
            s.pop();
            std::array<int,2> t1;
            t1=s.top();
            if(n[1]+1 == t1[1])
            {
                std::cerr<<"up";
                Mouse::motion('u');
            }
            if(n[0]+1 == t1[0])
            {
                std::cerr<<"right";
                Mouse::motion('r');
            }
            if(n[1]-1 == t1[1])
            {
                std::cerr<<"down";
                Mouse::motion('d');
            }
            if(n[0]-1 == t1[0])
            {
                std::cerr<<"left";
                Mouse::motion('l');
            }
        }
        else
        {
            return false;
        }
    }
    if(!s.empty())
    {
        n=s.top();
        std::cerr<<'\n'<<n[0]<<'\t'<<n[1]<<'\n';
        search_maze(n,g);
    }
    else
    {
        return false;
    }
}

} // namespace rwa2;

