#include "circle.h"

void Circle::update() {
	//Vector2 mousePosition = GetMousePosition();
	//draw(mousePosition, getSize, getColor);
}
void Circle::draw() {
	DrawCircleV(m_position, m_size, m_color);
}