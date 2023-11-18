#pragma once
#include <vector>
#include "playground2.hpp"
#include "constants.hpp"

class Snake {
	public:
		Playground2 *pg2;
		void Update();
		void Draw();
		void getDirection();
	private:
		ImVec2 pos;
		uint8_t	direction = DIR_DOWN;
};