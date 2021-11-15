#include <iostream>
#include <array>
#include <algorithm>
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

int main() {
	rwa2::Mouse mouse;
	mouse.display_walls();

	while(true)
	{
		API::clearAllColor();
		API::setColor(8,8,'g');
		API::setText(8,8,"G");
		std::array<int,2> curr_mou_pos = {mouse.ret_m_x(),mouse.ret_m_y()};
		std::array<int,2>  goal_pos = {8,8};
		int curr_mou_dir = mouse.ret_m_dir();
		mouse.search_maze(curr_mou_pos,goal_pos);
		if (mouse.search_maze(curr_mou_pos,goal_pos))
		{
			std::cout<<"No Path Found";
			break;
		}
		std::stack <std::array<int,2>>sol_path;
		sol_path = mouse.sol();
		while(!sol_path.empty())
		{
			std::array <int,2> path = sol_path.top();
			if(curr_mou_dir == 0)
			{
				if(path[1]==curr_mou_pos[1]+1)
				{
					API::moveForward();
				}
				else if(path[0]==curr_mou_pos[0]+1)
				{
					API::turnRight();
					API::moveForward();
				}
				else if(path[1]==curr_mou_pos[1]-1)
				{
					API::turnRight();
					API::turnRight();
					API::moveForward();
				}
				else
				{
					API::turnLeft();
					API::moveForward();
				}
			}
			else if(curr_mou_dir == 1)
			{
				if(path[0]==curr_mou_pos[0]+1)
				{
					API::moveForward();
				}
				else if(path[1]==curr_mou_pos[1]+1)
				{
					API::turnLeft();
					API::moveForward();
				}
				else if(path[0]==curr_mou_pos[0]-1)
				{
					API::turnRight();
					API::turnRight();
					API::moveForward();
				}
				else
				{
					API::turnRight();
					API::moveForward();
				}
			}
			else if(curr_mou_dir == 2)
			{
				if(path[1]==curr_mou_pos[1]-1)
				{
					API::moveForward();
				}
				else if(path[0]==curr_mou_pos[0]+1)
				{
					API::turnLeft();
					API::moveForward();
				}
				else if(path[1]==curr_mou_pos[1]+1)
				{
					API::turnRight();
					API::turnRight();
					API::moveForward();
				}
				else
				{
					API::turnRight();
					API::moveForward();
				}
			}
			else
			{
				if(path[0]==curr_mou_pos[0]-1)
				{
					API::moveForward();
				}
				else if(path[1]==curr_mou_pos[1]-1)
				{
					API::turnLeft();
					API::moveForward();
				}
				else if(path[0]==curr_mou_pos[0]+1)
				{
					API::turnRight();
					API::turnRight();
					API::moveForward();
				}
				else
				{
					API::turnRight();
					API::moveForward();
				}
			}
		}
	}

}

