#pragma once
#pragma once
#include "../externals/imgui/imgui.h"
#include "../externals/imgui/backends/imgui_impl_glfw.h"
#include "../externals/imgui/backends/imgui_impl_opengl3.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include "../../GLFW/glfw3.h" // Will drag system OpenGL headers
#include <vector>
#include "constants.hpp"
using namespace std;

class Snake {
	public:
				Snake();
		void	Update();
		void	Draw();

		ImDrawList *dl;
		ImGuiIO *io;

	private:
		uint8_t			direction	= DIR_DOWN;
		ImVec2			applePos;
		uint16_t		appleEaten	= 0.f;
		ImVec2			tailTemp;
		vector<ImVec2>	tail = {{5.f, 7.f}};
		float			updateCap	= UPDATE_CAP;
		float			updateTimer	= 0.f;

		ImVec2	Movement(size_t);
		void	getDirection();
		
		//Debug
		void	DebugInfo();
};