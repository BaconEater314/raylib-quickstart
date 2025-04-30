/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "circle.h"
#include "square.h"

#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "raymath.h"
#include "vector"
#include "random"
#include "images.h"
#include <string>
//#include <iostream>

//constant variables
const float screen_width = 1600;
const float screen_height = 950;
const int speed = 10;

int counter = 0;


int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screen_width, screen_height, "");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	//Texture krill = LoadTexture("krill.png");
	Texture image = LoadTexture("maple.jpg");

	Shape* maple = new ImageShape(LoadTexture("maple.jpg"), Vector2{500, 500}, 100.0f, WHITE);
	//Shape* shape = new Circle(Vector2{ 400, 400 }, 40.0f, WHITE);
	Shape* shape2 = new Square(Vector2{ 500,500 }, 40.f, WHITE);
	std::vector<Shape*> shapes;
	bool selection = true;
	shape2->draw();
	maple->draw();
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		BeginDrawing();
		ClearBackground(BLACK);

		//std::string num = std::to_string(counter);
		std::string updatedScore = "Score: " + std::to_string(counter);
		char* score = const_cast < char*>(updatedScore.c_str());
		DrawText(score, 50, 50, 40, WHITE);
		counter += 1;
		
		//shape->draw();
		
		if (IsKeyPressed(KEY_RIGHT)) {
			Vector2 position = maple->getPosition();
			position.x += speed;
			maple->update(position);
		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
