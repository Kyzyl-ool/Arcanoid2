#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"
#include "PhysicsManager.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main main_window
    main_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Arcanoid");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    
    main_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    main_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    //Creating main game objects
    GraphicsManager GManager(main_window);
    PhysicsManager  PManager;
    
    Background b(60);
    Board support;
    Ball ball;
    
    int space[MAX_BLOCKS_Y][MAX_BLOCKS_X] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    };
    Brick* bricks[MAX_BLOCKS_X*MAX_BLOCKS_Y] = {nullptr};
    for (int i = 0; i < MAX_BLOCKS_Y; i++)
        for (int j = 0; j < MAX_BLOCKS_X; j++)
        {
            if (space[i][j] != -1)
            {
                bricks[i*MAX_BLOCKS_X + (j % MAX_BLOCKS_X)] = new Brick(space[i][j], j*BLOCK_WIDTH, i*BLOCK_HEIGHT);
            }
        }
    
    //Loading all game objects to game manager's array
    GManager.AddGameObject(&b);
    GManager.AddGameObject(&support);
    GManager.AddGameObject(&ball);
    
    PManager.AddGameObject(&support);
    PManager.AddGameObject(&ball);
    for (int i = 0; i < MAX_BLOCKS_Y*MAX_BLOCKS_X; i++)
    {
        if (bricks[i] != nullptr)
        {
            GManager.AddGameObject(bricks[i]);
            PManager.AddGameObject(bricks[i]);
        }
    }
    // Start the game loop
    while (main_window->isOpen())
    {
        // Process events
        sf::Event event;
        while (main_window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    main_window->close();
                }
                case sf::Event::KeyPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {
                            main_window->close();
                            break;
                        }
                            
                        case sf::Keyboard::Right:
                        {
                            support.setVelocity(20);
                            break;
                        }
                        case sf::Keyboard::Left:
                        {
                            support.setVelocity(-20);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Mouse::Left:
                        {
                            ball.release();
                            ball.setVelocity(0, -10);
                            break;
                        }
                        default: break;
                    }
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Right:
                        case sf::Keyboard::Left:
                        {
                            support.setVelocity(0);
                            break;
                        }
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }
        
        //        support.dump();
        
        // Clear screen
        main_window->clear();
        GManager.DrawAllObjects();
        PManager.UpdateAllObjects();
        // Update the main_window
        main_window->display();
    }
    
    return EXIT_SUCCESS;
}
