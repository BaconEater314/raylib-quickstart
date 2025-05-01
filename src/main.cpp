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
#include <ctime>
#include <list>
//#include <iostream>

//constant variables
const float screen_width = 1600;
const float screen_height = 950;
const int speed = 15;

std::list<Square> shapes;

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

	
	//Shape* shape = new Circle(Vector2{ 400, 400 }, 40.0f, WHITE);
	Square* projectile = new Square;
	std::vector<Shape*> shapes;
	bool selection = true;
	Shape* maple;
	Square* hitbox;
	Square* projectileHitbox;
	bool start = true;
	bool alive = true;
	int health = 5;
	int counter = 0;
	bool invincibility = false;
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		BeginDrawing();
		ClearBackground(BLACK);

		//start drawings
		if (start) {
			maple = new ImageShape(LoadTexture("maple.jpg"), Vector2{500, 500}, 125.0f, WHITE);
			hitbox = new Square(Vector2{ 500,500 }, 125.0f, WHITE);
			//DrawRectangle(500, 500, 125, 125, WHITE);
			maple->draw();
			//hitbox->draw();
			start = false;
		}
		//score updating code and bullet amount
		if (alive) {
			std::string updatedScore = "Score: " + std::to_string(counter);
			char* score = const_cast <char*>(updatedScore.c_str());
			DrawText(score, 50, 50, 40, WHITE);
			if (maple->getPosition().x > screen_width * 0.75f) {
				counter += 3;
			}
			else if (maple->getPosition().x > screen_width / 2) {
				counter += 2;
			}
			else {
				counter += 1;
			}
			//counter = std::rand() % 950;
		}
		else {
			std::string updatedScore = "Game Over! Score: " + std::to_string(counter);
			char* score = const_cast <char*>(updatedScore.c_str());
			DrawText(score, 50, 50, 40, WHITE);
		}

		//health text updating code
		if (health > 0) {
			std::string updatedHealth = "Health: " + std::to_string(health);
			char* current = const_cast <char*>(updatedHealth.c_str());
			DrawText(current, 1000, 50, 40, WHITE);
		}
		if (health <= 0) {
			health == 0;
			std::string updatedHealth = "Health: " + std::to_string(health);
			char* current = const_cast <char*>(updatedHealth.c_str());
			DrawText(current, 1000, 50, 40, WHITE);
			alive = false;
			delete(maple);
			delete(hitbox);
			shapes.clear();
		}
		

		//movement if statements
		Vector2 position = maple->getPosition();
		if (IsKeyDown(KEY_RIGHT)) {
			position.x += speed;
			maple->update(position);
			hitbox->update(position);
		}
		if (IsKeyDown(KEY_LEFT)) {
			position.x -= speed;
			maple->update(position);
			hitbox->update(position);
		}
		if (IsKeyDown(KEY_UP)) {
			position.y -= speed;
			maple->update(position);
			hitbox->update(position);
		}
		if (IsKeyDown(KEY_DOWN)) {
			position.y += speed;
			maple->update(position);
			hitbox->update(position);
		}

		maple->update(position);
		if (position.y > 900) {
			position.y = 900;
			maple->update(position);
			hitbox->update(position);
		}else if (position.y < 50) {
			position.y = 50;
			maple->update(position);
			hitbox->update(position);
		}
		if (position.x < 50) {
			position.x = 50;
			maple->update(position);
			hitbox->update(position);
		}else if (position.x > 1550) {
			position.x = 1550;
			maple->update(position);
			hitbox->update(position);
		}

		//projectile spawning code
		int range = 100;
		if (counter % 1000 == 0) {
			range += 5;
		}
		int rand = std::rand() % range;
		if (rand >= 90){
			float randomY = std::rand() % 950;
			projectile = new Square(Vector2{ screen_width, randomY }, 40.f, WHITE);
			//projectileHitbox = new Square(Vector2{ screen_width,randomY }, 40.0f, WHITE);
			//projectile->draw();
			shapes.push_back(projectile);
		}
		
		for (int i = 0; i < shapes.size(); i++) {
			Vector2 position = shapes[i]->getPosition();
			shapes[i]->draw();
			position.x -= speed+5;
			shapes[i]->update(position);
			shapes[i]->setPosition(position);
			DrawRectangle(position.x, position.y, shapes[i]->getSize() * 3, shapes[i]->getSize() * 0.6f, WHITE);
		}

		//updating maple and hitbox positions
		maple->setPosition(position);
		hitbox->setPosition(position);

		//DrawRectangle(position.x, position.y, 125, 125, WHITE);
		/*if (CheckCollisionRecs() && !invicibility) {
			health -= 1;
			invicibility = true;
		}*/
		if (invincibility = true) {
			
			
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
