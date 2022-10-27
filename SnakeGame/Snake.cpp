#include "Snake.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

constexpr float kHeadSize{ 20.0f };

Snake::Snake(sf::Vector2f position)
{
	m_segments.push_back(position);
}

void Snake::ChangeDirection(Direction newDirection)
{
	m_direction = newDirection;
}


void Snake::Update()
{
	if (isAlive)
	{
		sf::Vector2f position = m_segments.front();
		switch (m_direction)
		{
		case Direction::eNorth:
			position.y -= kHeadSize;
			break;
		case Direction::eEast:
			position.x += kHeadSize;
			break;
		case Direction::eSouth:
			position.y += kHeadSize;
			break;
		case Direction::eWest:
			position.x -= kHeadSize;
			break;
		default:
			std::cout << "Unhandled enum" << std::endl;
			break;
		}

		m_segments.emplace(m_segments.begin(), position);
		if (m_growamount > 0)
		{
			m_growamount = m_growamount - 1;
		}
		else
		{
			m_segments.pop_back();
		}
	}
}

sf::Vector2f Snake::returnSnaPos()
{
	return (m_segments.front());
}

std::vector<sf::Vector2f> Snake::resturnSegmentPos()
{
	std::vector<sf::Vector2f> TailSegments;
	TailSegments = m_segments;
	TailSegments.erase(TailSegments.begin());
	return (TailSegments);
}



void Snake::IncreaseGrow()
{
	srand(time(0));
	m_growamount = m_growamount + (rand() % 3 + 1);

}

void Snake::Render(sf::RenderWindow& window)
{
	sf::CircleShape snake(kHeadSize/2.0f);
	if (isAlive) 
	{
		snake.setFillColor(sf::Color::Green);
	}
	else
	{
		snake.setFillColor(sf::Color::Red);
	}
	
	for (sf::Vector2f pos : m_segments)
	{
		snake.setPosition(pos);
		window.draw(snake);
	}
}


