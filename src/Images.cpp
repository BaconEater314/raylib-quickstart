#include "images.h"

void ImageShape::update(Vector2 position) {
	draw(position);
}

void ImageShape::update() {
	
}

void ImageShape::draw() {
	Rectangle src{ 0,0,(float)m_texture.width, (float)m_texture.height };
	Rectangle dest{ m_position.x,m_position.y,m_size,m_size };

	DrawTexturePro(m_texture, src, dest, Vector2{m_size / 2.0f,m_size / 2.0f },0, m_color);
}

void ImageShape::draw(Vector2 position) {
	Rectangle src{ 0,0,(float)m_texture.width, (float)m_texture.height };
	Rectangle dest{ position.x,position.y,m_size,m_size };

	DrawTexturePro(m_texture, src, dest, Vector2{ m_size / 2.0f,m_size / 2.0f }, 0, m_color);
}