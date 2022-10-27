#include "Game.h"
#include "Snake.h"
#include "Collectable.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>


void Game::Run()
{
    srand(time(0));
  // All SFML types and functions are contained in the sf namespace

    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Snake Game by Andrew Hartley");

    // We can still output to the console window
    std::cout << "SnakeGame: Starting" << std::endl;

    //Create a Snake
    m_snakes.push_back(new Snake(sf::Vector2f(400.0f, 400.0f)));

    //Create a collectable
    for (int i = 0; i < 5; i++)
    {
        m_collectableVector.push_back(new Collectable());
    }

    sf::Clock clock;

    // Main loop that continues until we call window.close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        //Simulation
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            m_snakes[0]->ChangeDirection(Direction::eWest);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            m_snakes[0]->ChangeDirection(Direction::eNorth);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            m_snakes[0]->ChangeDirection(Direction::eSouth);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            m_snakes[0]->ChangeDirection(Direction::eEast);

        for (Snake* snake : m_snakes)
            snake->Update();

        // We must clear the window each time around the loop
        window.clear();
        
        for (Snake* snake : m_snakes)
            snake->Render(window);
        
        if (rand()%5 == 0)
        {
            for (Collectable* col : m_collectableVector)
            {
                if (!col->GetIsAlive())
                {
                    col->Spawn();
                    break;
                }
            }
        }

        for (Collectable* col : m_collectableVector)
        {
            sf::Vector2f col_pos = col->returnColPos();
            if (col->GetIsAlive())
            {
                for (Snake* snake : m_snakes)
                {
                    sf::Vector2f sna_pos = snake->returnSnaPos();
                    if (col_pos == sna_pos)
                    {
                        snake->IncreaseGrow();
                        col->Kill();
                        if (difficulty > 100) {
                            difficulty = difficulty - 50;
                        }
                        m_collectableVector;
                    }
                    for (int i=0; i < snake->resturnSegmentPos().size(); i++)
                    {
                        if (snake->returnSnaPos() == snake->resturnSegmentPos()[i])
                        {
                            snake->isAlive = false;
                        }
                    }
                    if (snake->returnSnaPos().x < 0 || snake->returnSnaPos().x > 780)
                    {
                        snake->isAlive = false;
                    }
                    else if (snake->returnSnaPos().y < 0 || snake->returnSnaPos().y > 580)
                    {
                        snake->isAlive = false;
                    }

                }
            }
        }
        for (Collectable* col : m_collectableVector)
        {
            if (col->GetIsAlive())
                col->Render(window);
        }


        // Get the window to display its contents
        window.display();


        //Loop Until time passed
        while (clock.getElapsedTime().asMilliseconds() < difficulty);
        clock.restart();
    }
    std::cout << "SnakeGame: Finished" << std::endl;
}