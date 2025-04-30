#include "square.h"

void Square::update() {
	/*Vector2 mousePosition = GetMousePosition();
	draw(mousePosition, getSize, getColor);*/
}
void Square::update(Vector2 position) {
}
void Square::draw() {
	DrawRectangleV(m_position, Vector2{m_size*4,m_size}, m_color);
}
void Square::draw(Vector2 position) {
	DrawRectangleV(position, Vector2{ m_size * 4,m_size }, m_color);
}