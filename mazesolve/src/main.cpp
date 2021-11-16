#include <iostream>
#include <array>
#include <algorithm>
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

int main() {
	rwa2::Mouse mouse;
	mouse.display_walls();

	API::clearAllColor();						//Reset the colour
	API::setColor(8,8,'g');						//Set the colour for goal node
	API::setText(8,8,"G");						//Set the text for goal node
	std::array<int,2> curr_mou_pos = {0,0}; 	//Initial position
	std::array<int,2>  goal_pos = {8,8};		//Goal position
	bool solution = mouse.search_maze(curr_mou_pos,goal_pos);
	if (!solution)
	{
		std::cout<<"No Path Found";				//If no solution found
	}
	return 0;
}

