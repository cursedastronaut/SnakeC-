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
		
		//Go through each tail section, and move them
		for (size_t i = tail.size()-1; i > 0 && i < tail.size(); --i) {
			Movement(i);
		}
		Movement(0);

		for (size_t i = 1; i < tail.size(); ++i)
			if (tail[0] == tail[i])
				scene = 2;

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
	for (size_t i = 0; i < tail.size();		cout << i << " " << tail[i].x << ":" << tail[i-1].x << endl;
 ++i)
		dl->AddRectFilled(tail[i]*CASE_SIZE, tail[i]*CASE_SIZE+CASE_SIZE, IM_COL32_WHITE);
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