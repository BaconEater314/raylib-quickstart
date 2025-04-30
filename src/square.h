#pragma once

#include "shape.h"

class Square : public Shape {
public:
	Square() = default;
	Square(const Vector2& position, float size = 20, Color& color = WHITE) :
		Shape(position, size, color)
	{
	}

	void update() override;
	void draw() override;
	void draw(Vector2 position) override;
	void update(Vector2 position) override;
	Type getType() override { return Type::Square; }
};