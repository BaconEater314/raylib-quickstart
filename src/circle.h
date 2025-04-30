#pragma once
#include "shape.h"

class Circle : public Shape {
public:
	Circle() = default;
	Circle(Vector2 position, float size = 20, Color& color = WHITE) :
		Shape(position, size, color)
	{}

	void update() override;
	void draw() override;
	void draw(Vector2 position) override;
	void update(Vector2 position) override;
	Type getType() override { return Type::Circle; }
};