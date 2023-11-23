#include "snake.h"
using namespace std;
int toInt(const char* index);

//Snake class constructor
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

//Main update function
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

		//Checks if snake head is beyond limit
		if (!loopAtBorders && (tail[0].x < 0 || tail[0].x >= GRID_SIZE.x || tail[0].y < 0 || tail[0].y >= GRID_SIZE.y))
			scene = SCENE_GAMEOVER;
		else
			borderLoop();

		//Checks if snake head is colliding with a tail section
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

//Handles snake head and tail movement
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

//Draws the snake, and the apple
void Snake::Draw() {
	for (size_t i = 0; i < tail.size(); ++i)
		dl->AddRectFilled(tail[i]*CASE_SIZE, tail[i]*CASE_SIZE+CASE_SIZE, IM_COL32_WHITE);
	dl->AddRectFilled(applePos*CASE_SIZE, applePos*CASE_SIZE+CASE_SIZE, IM_COL32_BLACK);
}

//Gets the user input to change to a direction
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

//Displays debug informations
void Snake::DebugInfo() {
	ImGui::Begin("Debug Informations");
	ImGui::Text("PlaygroundSize: %d, %d", GRID_SIZE.x, GRID_SIZE.y);
	ImGui::Text("Apple position: %f, %f", applePos.x, applePos.y);
	for (size_t i = 0; i < tail.size(); ++i)
		ImGui::Text("Snake%ld : %f, %f", i, tail[i].x, tail[i].y);
	ImGui::End();
}

//Resets values of snake object to launch game again.
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

//Make the snake head loop around the border
void Snake::borderLoop() {
	if (tail[0].x >= GRID_SIZE.x)
		tail[0].x = 0;
	else if (tail[0].y >= GRID_SIZE.y)
		tail[0].y = 0;
	else if (tail[0].x < 0)
		tail[0].x = GRID_SIZE.x - 1;
	else if (tail[0].y < 0)
		tail[0].y = GRID_SIZE.y - 1;
}

//Handles user's command line arguments, returns true if the program should exit.
bool Snake::setUserArgs(const int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], "--loop") == 0) {
			loopAtBorders = true;
		} else if (strcmp(argv[i], "--skip") == 0) {
			scene = 1;
		} else if (strcmp(argv[i], "--gridx") == 0) {
			if (i >= argc - 1) {
				cout	<< "Error: --gridx argument is empty." << endl
						<< "Syntax is --gridx [grid horizontal size]" << endl;
				return true;
			} else {
				GRID_SIZE.x = (float)toInt(argv[i+1]);
				if (GRID_SIZE.x == 0) {
					cout << "Erreur: Invalid value at --gridx" << endl;
					return true;
				}
			}
		} else if (strcmp(argv[i], "--gridy") == 0) {
			if (i >= argc - 1) {
				cout	<< "Error: --gridy argument is empty." << endl
						<< "Syntax is --gridy [grid horizontal size]" << endl;
				return true;
			} else {
				GRID_SIZE.y = (float)toInt(argv[i+1]);
				if (GRID_SIZE.y == 0) {
					cout << "Erreur: Invalid value at --gridy" << endl;
					return true;
				}
			}
		} else if (strcmp(argv[i], "--help") == 0) {
			cout	<< "Snake by @cursedastronaut on Github" << endl
					<< "\t- `--loop`\n\t\tAllows player to loop around borders instead of having a game over." << endl
					<< "\t- `--x [width]`\n\t\tAllows player to choose their horizontal grid size. Default is 40." << endl
					<< "\t- `--y [height]`\n\t\tAllows player to choose their vertical grid size. Default is 30." << endl
					<< "\t- `--skip`\n\t\tAllows player to skip the main menu." << endl;
					return true;
		}
	}
	return false;
}

int toInt(const char* index) {
	std::string temp = index;
	if (temp.size() == 0)
		return 0;
	int result = 0;	

	for (size_t i = temp.size()-1; i < temp.size(); --i)
	{
		if (temp[i] < '0' || temp[i] > '9') {
			return 0;
		}
		result += (temp[i] - '0') * std::pow(10, temp.size()-1-i);
	}
	return result;
}