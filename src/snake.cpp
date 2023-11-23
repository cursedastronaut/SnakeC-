#include "snake.h"
using namespace std;

Snake::Snake() {
	updateCap = UPDATE_CAP;
	updateTimer = 0.f;
	srand(time(NULL)); // Seed the time
	applePos = {
		static_cast<float>(rand() % (int)(GRID_SIZE.x)) ,
		static_cast<float>(rand() % (int)(GRID_SIZE.y)) 
	};
}

void Snake::Update() {
	getDirection();
	if (updateTimer >= updateCap) {
		updateTimer = 0.f;
		Movement();
		if (pos == applePos) {
			applePos = {
				static_cast<float>(rand() % (int)(GRID_SIZE.x)) ,
				static_cast<float>(rand() % (int)(GRID_SIZE.y)) 
			};
			++ appleEaten;
		}
	}
	updateTimer += io->DeltaTime;
	DebugInfo();
}

void Snake::Movement() {
	switch(direction) {
		case DIR_UP:
			pos.y --;
			break;
		case DIR_LEFT:
			pos.x --;
			break;
		case DIR_DOWN:
			pos.y ++;
			break;
		case DIR_RIGHT:
			pos.x ++;
			break;
		default:
			break;
	}
}

void Snake::Draw() {
	dl->AddRectFilled(pos*CASE_SIZE, pos*CASE_SIZE+CASE_SIZE, IM_COL32_WHITE);
	dl->AddRectFilled(applePos*CASE_SIZE, applePos*CASE_SIZE+CASE_SIZE, IM_COL32_BLACK);
}

void Snake::getDirection() {
	if (ImGui::IsKeyPressed(ImGuiKey_UpArrow))
		direction = DIR_UP;
	if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow))
		direction = DIR_LEFT;
	if (ImGui::IsKeyPressed(ImGuiKey_DownArrow))
		direction = DIR_DOWN;
	if (ImGui::IsKeyPressed(ImGuiKey_RightArrow))
		direction = DIR_RIGHT;
}

void Snake::DebugInfo() {
	ImGui::Begin("Debug Informations");
	ImGui::Text("PlaygroundSize: %d, %d", GRID_SIZE.x, GRID_SIZE.y);
	ImGui::Text("Snake position: %f, %f", pos.x, pos.y);
	ImGui::Text("Apple position: %f, %f", applePos.x, applePos.y);
	ImGui::End();
}