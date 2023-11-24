#pragma once
#ifndef __SNAKE_CLASS__
#define __SNAKE_CLASS__
#include "../externals/include/imgui/imgui.h"
#include "../externals/include/imgui/backends/imgui_impl_glfw.h"
#include "../externals/include/imgui/backends/imgui_impl_opengl3.h"
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include "../externals/include/GLFW/glfw3.h" // Will drag system OpenGL headers
#include <vector>
#include "constants.hpp"
#include <bits/stdc++.h> 
using namespace std;



class Snake {
	public:
		//Class Constructor
				Snake();
		//Main update function
		void	Update();
		//Draws the snake, and the apple
		void	Draw();
		//Resets values of snake object to launch game again.
		void	Reset();
		//Handles user's command line arguments
		bool	setUserArgs(const int argc, char* argv[]);
		//Sends user to Game Over scene
		void	gameOver();
		//Reads and write to save
		void	saveBestScore();

		ImDrawList		*dl;
		ImGuiIO			*io;
		uint8_t			scene	= 0;

		bool			loopAtBorders = false;
		bool			debugMode = false;
		uint8_t2		GRID_SIZE		=	{40, 30};

	private:
		uint8_t			direction	= DIR_DOWN;
		uint8_t			previousDirection	= DIR_DOWN;
		ImVec2			applePos;
		uint16_t		appleEaten	= 0.f;
		ImVec2			tailTemp;
		vector<ImVec2>	tail = {{5.f, 7.f}};
		float			updateCap	= UPDATE_CAP;
		float			updateTimer	= 0.f;

		//Handles snake head and tail movement
		ImVec2	Movement(size_t);
		//Make the snake head loop around the border
		void	borderLoop();
		//Gets the user input to change to a direction
		void	getDirection();
		
		//Displays debug informations
		void	DebugInfo();
};
#endif
