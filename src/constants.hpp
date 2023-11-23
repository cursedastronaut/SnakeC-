#pragma once
#include <iostream>
#include "../externals/imgui/imgui.h"
struct uint8_t2	{	uint8_t	x;	uint8_t	y;	};
const ImVec2	CASE_SIZE		=	{16, 16};
const uint8_t2	GRID_SIZE		=	{static_cast<int>(std::round(640.f/CASE_SIZE.x)), static_cast<int>(std::round(480.f/CASE_SIZE.y))};

const uint8_t	DIR_UP			=	0;
const uint8_t	DIR_LEFT		=	1;
const uint8_t	DIR_DOWN		=	2;
const uint8_t	DIR_RIGHT		=	3;

const float		UPDATE_CAP		=	0.3f;
const uint8_t	SCENE_MAINMENU	=	0;
const uint8_t	SCENE_GAME		=	1;
const uint8_t	SCENE_GAMEOVER	=	2;