#pragma once
#include "shape.h"

class ImageShape : public Shape {
public:
	ImageShape() = default;
	ImageShape(const Texture2D& texture, const Vector2& position, float size = 20, const Color& color = WHITE) :
		Shape(position, size, color),
		m_texture {texture}
	{}
	void draw() override;
	void update() override;
	void draw(Vector2 position) override;
	void update(Vector2 position) override;
	void setTexture(const Texture2D texture) {m_texture = texture;}

	Type getType() override { return Type::Image; }
protected:
	Texture2D m_texture;
};