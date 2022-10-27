#pragma once
#include "SFML/Graphics.hpp"

class Collectable
{
private:
	bool m_alive{ false };
	sf::Vector2f m_pos;
public:
	bool GetIsAlive() const { return m_alive; }
	void Spawn();
	void Kill();
	void Render(sf::RenderWindow& window);
	sf::Vector2f returnColPos();
};

