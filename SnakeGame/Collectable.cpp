#include "Collectable.h"
#include <iostream>

void Collectable::Spawn()
{
	float x = 40 * (rand() % 20);
	float y = 40 * (rand() % 15);
	m_pos = sf::Vector2f((float)x, (float)y);
	m_alive = true;
}

void Collectable::Kill()
{
	m_alive = false;
}

void Collectable::Render(sf::RenderWindow& window)
{
	sf::CircleShape col(10);
	col.setFillColor(sf::Color::White);
	col.setPosition(m_pos);

	window.draw(col);
}

sf::Vector2f Collectable::returnColPos()
{
	return m_pos;
}
