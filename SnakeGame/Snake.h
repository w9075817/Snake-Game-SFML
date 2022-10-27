#pragma once
#include "SFML/Graphics.hpp"
#include <list>

enum class Direction
{
	eNorth,
	eEast,
	eSouth,
	eWest
};


class Snake
{
private:
	Direction m_direction{ Direction::eNorth };
	std::vector<sf::Vector2f> m_segments;
	int m_growamount = 0;
public:
	void IncreaseGrow();
	void ChangeDirection(Direction newDirection);
	bool isAI = false;
	bool isAlive = true;

	Snake(sf::Vector2f position); 
	void Update();
	void Render(sf::RenderWindow& window);
	sf::Vector2f returnSnaPos();
	std::vector<sf::Vector2f> resturnSegmentPos();
};

