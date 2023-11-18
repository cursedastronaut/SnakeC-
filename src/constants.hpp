#pragma once
#include <iostream>
#include "../externals/imgui/imgui.h"

const ImVec2 CASE_SIZE		= {16, 16};
const ImVec2 GRID_SIZE_X	= {640/CASE_SIZE.x, 480/CASE_SIZE.y};

const uint8_t DIR_UP		= 0;
const uint8_t DIR_LEFT		= 1;
const uint8_t DIR_DOWN		= 2;
const uint8_t DIR_RIGHT		= 3;