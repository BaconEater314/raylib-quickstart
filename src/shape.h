#pragma once
#include "raylib.h"

class Shape {
public:
	enum class Type {
		Circle,
		Square,
		Image
	};
public:
	Shape() = default;
	Shape(Vector2 position, float size = 20, const Color& color = WHITE) :
		m_position{ position },
		m_size{ size },
		m_color{ color }
	{}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual Type getType() = 0;
	virtual void draw(Vector2 position) = 0;
	virtual void update(Vector2 position) = 0;

	const Vector2& getPosition() const { return m_position; }
	void setPosition(const Vector2& position) { m_position = position; }

	float getSize() const { return m_size; }
	void setSize(float size) { m_size = size; }

	const Color& getColor() const { return m_color; }
	void setColor(Color color) { m_color = color; }

protected:
	Color m_color = WHITE;
	float m_size = 20;
	Vector2 m_position;
};
