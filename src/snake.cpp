#include "snake.h"
using namespace std;

Snake::Snake() {
	updateCap = 0.5f;
	updateTimer = 0.f;
}

void Snake::Update() {
	getDirection();
	if (updateTimer >= updateCap) {
		cout << updateCap << endl;
		Movement();
		updateTimer = 0.f;
	}
	updateTimer += io->DeltaTime;
}

void Snake::Movement() {
	switch(direction) {
		case DIR_UP:
			pos.y -= CASE_SIZE.y;
			break;
		case DIR_LEFT:
			pos.x -= CASE_SIZE.x;
			break;
		case DIR_DOWN:
			pos.y += CASE_SIZE.y;
			break;
		case DIR_RIGHT:
			pos.x += CASE_SIZE.x;
			break;
		default:
			break;
	}
}

void Snake::Draw() {
	dl->AddRectFilled(pos, pos+CASE_SIZE, IM_COL32_WHITE);
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