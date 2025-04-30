#pragma once

#include "shape.h"
#include <vector>
#include <array>

class Editor {
public:
	Editor();
	~Editor();

	void update();
	void draw();

private:
	float m_size = 20;
	Shape::Type m_type = Shape::Type::Circle;
	const std::array<Color, 7> m_colors = { WHITE,GREEN,RED,BLUE,PURPLE,SKYBLUE,MAGENTA};
	int m_colorIndex = 0;

	Shape* m_shape = nullptr;
	std::vector<Shape*> m_shapes
};