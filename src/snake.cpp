#include "snake.h"
using namespace std;

Snake::Snake() {
	updateCap = UPDATE_CAP;
	updateTimer = 0.f;

	tail = {{5.f, 7.f}};
	tailTemp = {-1, -1};
	scene = 0;
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

		previousDirection = direction;
		
		//Go through each tail section, and move them
		for (size_t i = tail.size()-1; i > 0 && i < tail.size(); --i) {
			Movement(i);
		}
		Movement(0);

		if (!loopAtBorders && (tail[0].x < 0 || tail[0].x >= GRID_SIZE.x || tail[0].y < 0 || tail[0].y >= GRID_SIZE.y))
			scene = SCENE_GAMEOVER;

		for (size_t i = 1; i < tail.size(); ++i)
			if (tail[0] == tail[i])
				scene = SCENE_GAMEOVER;

		if (tailTemp.x != -1 && tailTemp.y != -1) {
			tail.push_back(tailTemp);
			tailTemp = {-1, -1};
		}

		if (tail[0] == applePos) {
			applePos = {
				static_cast<float>(rand() % (int)(GRID_SIZE.x)) ,
				static_cast<float>(rand() % (int)(GRID_SIZE.y)) 
			};
			++ appleEaten;
			tailTemp = tail[tail.size()-1];
		}
	}
	updateTimer += io->DeltaTime;
	DebugInfo();
}

ImVec2 Snake::Movement(size_t i) {
	ImVec2 prevPos = tail[i];
	if (i == 0) {
		switch(direction) {
			case DIR_UP:
				tail[i].y --;
				break;
			case DIR_LEFT:
				tail[i].x --;
				break;
			case DIR_DOWN:
				tail[i].y ++;
				break;
			case DIR_RIGHT:
				tail[i].x ++;
				break;
			default:
				break;
		}
	}
	else {
		tail[i] = tail[i-1];
	}

	return prevPos;
}

void Snake::Draw() {
	for (size_t i = 0; i < tail.size(); ++i)
		dl->AddRectFilled(tail[i]*CASE_SIZE, tail[i]*CASE_SIZE+CASE_SIZE, IM_COL32_WHITE);
	dl->AddRectFilled(applePos*CASE_SIZE, applePos*CASE_SIZE+CASE_SIZE, IM_COL32_BLACK);
}

void Snake::getDirection() {
	if (ImGui::IsKeyPressed(ImGuiKey_UpArrow)		&& (tail.size() < 2 || previousDirection != DIR_DOWN))
		direction = DIR_UP;
	if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow)		&& (tail.size() < 2 || previousDirection != DIR_RIGHT))
		direction = DIR_LEFT;
	if (ImGui::IsKeyPressed(ImGuiKey_DownArrow)		&& (tail.size() < 2 || previousDirection != DIR_UP))
		direction = DIR_DOWN;
	if (ImGui::IsKeyPressed(ImGuiKey_RightArrow)	&& (tail.size() < 2 || previousDirection != DIR_LEFT))
		direction = DIR_RIGHT;
}

void Snake::DebugInfo() {
	ImGui::Begin("Debug Informations");
	ImGui::Text("PlaygroundSize: %d, %d", GRID_SIZE.x, GRID_SIZE.y);
	ImGui::Text("Apple position: %f, %f", applePos.x, applePos.y);
	for (size_t i = 0; i < tail.size(); ++i)
		ImGui::Text("Snake%ld : %f, %f", i, tail[i].x, tail[i].y);
	ImGui::End();
}

void Snake::Reset() {
	tail = {{5.f, 7.f}};
	tailTemp = {-1, -1};
	scene = 1;
	srand(time(NULL)); // Seed the time
	applePos = {
		static_cast<float>(rand() % (int)(GRID_SIZE.x)) ,
		static_cast<float>(rand() % (int)(GRID_SIZE.y)) 
	};
}