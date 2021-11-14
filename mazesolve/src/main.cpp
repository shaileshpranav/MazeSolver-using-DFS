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
		API::setColor('8','8','g');
		API::setText('8','8',"Goal");
		std::array<int,2> curr_mou_pos = {mouse.ret_m_x(),mouse.ret_m_y()};
		std::array<int,2>  goal_pos = {8,8};
		int curr_mou_dir = mouse.ret_m_dir();
		mouse.search_maze(curr_mou_pos,goal_pos);
		if (!mouse.search_maze(curr_mou_pos,goal_pos))
		{
			std::cout<<"No Path Found";
			// break;
		}
		std::stack <std::array<int,2>>sol_path;
		sol_path = mouse.sol();
		// for(int i=0;i<=sol_path.size();i++)
		// {	
			std::array<int,2> x {sol_path.top()};
			std::cout<<x[0]<<'\t'<<x[1];
		// 	sol_path.pop();
		// }
		// while(curr_mou_pos==sol_path.top())
		// {
		// 	if(curr_mou_pos[])
		// 	{

		// 	}
		// }
	}

}

