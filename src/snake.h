#pragma once
#pragma once
#include "../externals/imgui/imgui.h"
#include "../externals/imgui/backends/imgui_impl_glfw.h"
#include "../externals/imgui/backends/imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include "../../GLFW/glfw3.h" // Will drag system OpenGL headers
#include <vector>
#include "constants.hpp"

class Snake {
	public:
				Snake();
		void	Update();
		void	Movement();
		void	Draw();
		void	getDirection();

		ImDrawList *dl;
		ImGuiIO *io;
		float updateCap		= 1.0f;
		float updateTimer	= 0.f;

	private:
		ImVec2 pos;
		uint8_t	direction = DIR_DOWN;
};