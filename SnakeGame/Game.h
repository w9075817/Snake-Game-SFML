#pragma once
#include <Vector>
#include <SFML/Graphics.hpp>

class Snake;
class Collectable;

class Game
{
private:
	std::vector<Snake*> m_snakes;
	std::vector<Collectable*> m_collectableVector;
	int Score = 0;
	int difficulty = 600;
public:
	void Run();
};

