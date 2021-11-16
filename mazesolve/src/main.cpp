#include <iostream>
#include <array>
#include <algorithm>
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

int main() {
	rwa2::Mouse mouse;
	mouse.display_walls();

	// while(true)
	// {
		API::clearAllColor();
		API::setColor(8,8,'g');
		API::setText(8,8,"G");
		std::array<int,2> curr_mou_pos = {0,0};
		std::array<int,2>  goal_pos = {8,8};
		bool solution = mouse.search_maze(curr_mou_pos,goal_pos);
		if (!solution)
		{
			std::cout<<"No Path Found";
			// break;
		}
	// }
	return 0;
}

