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

class Playground2 {
	public:
		Playground2();
		//ImGui drawlist
		ImDrawList *dl;
		ImGuiIO *io;
		float updateCap;
		float updateTimer = 0.f;
};

struct uint8_t2 {
	uint8_t x;
	uint8_t y;
};
