//
//  GameManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GameManager.hpp"
#include "Defines.h"

const int map1[MAX_BLOCKS_Y][MAX_BLOCKS_X] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};


GameManager::GameManager(sf::RenderWindow* iMainWindow):
MainWindow(iMainWindow),
MainObjectManager(ObjectManager(MainWindow)),
MainGraphicsManager(GraphicsManager(&MainObjectManager)),
MainPhysicsManager(PhysicsManager(&MainObjectManager)),
MainBackground(Background(1)),
TheBoard(Board()),
TheBall(Ball(this))
{
    //Creating main game objects
    
    for (int i = 0; i < MAX_BLOCKS_Y; ++i) {
        for (int j = 0; j < MAX_BLOCKS_X; j++) {
            Space[i][j] = map1[i][j];
        }
    }
    
    
    Brick* Bricks[MAX_BLOCKS_Y][MAX_BLOCKS_X];
    
    for (int i = 0; i < MAX_BLOCKS_Y; ++i) {
        for (int j = 0; j < MAX_BLOCKS_X; j++) {
            Bricks[i][j] = nullptr;
        }
    }
    
    for (int i = 0; i < MAX_BLOCKS_Y; i++)
        for (int j = 0; j < MAX_BLOCKS_X; j++)
        {
            if (Space[i][j] != -1)
            {
                Bricks[i][j] = new Brick(Space[i][j], j*BLOCK_WIDTH, i*BLOCK_HEIGHT);
            }
        }
    
    
    
    
    
    //    Loading all game objects to game manager's array
    MainObjectManager.AddGameObject(&MainBackground);
    MainObjectManager.AddGameObject(&TheBoard);
    MainObjectManager.AddGameObject(&TheBall);
    
    for (int i = 0; i < MAX_BLOCKS_Y; i++)
    {
        for (int j = 0; j < MAX_BLOCKS_X; j++)
            if (Bricks[i] != nullptr)
            {
                MainObjectManager.AddGameObject(Bricks[i][j]);
            }
    }
}

void GameManager::CheckKeyboard()
{
    switch(MainEvent.key.code)
    {
        case sf::Keyboard::Escape:
        {
            MainWindow->close();
            break;
        }
        case sf::Keyboard::Right:
        {
            TheBoard.setVelocity(20);
            break;
        }
        case sf::Keyboard::Left:
        {
            TheBoard.setVelocity(-20);
            break;
        }
        case sf::Keyboard::Space:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

void GameManager::CheckKeyboardRelease()
{
    switch (MainEvent.key.code)
    {
        case sf::Keyboard::Right:
        case sf::Keyboard::Left:
        {
            TheBoard.setVelocity(0);
            break;
        }
        default: break;
    }
}

void GameManager::CheckMousePress()
{
    switch(MainEvent.key.code)
        {
            case sf::Mouse::Left:
            {
                TheBall.release();
                TheBall.setVelocity(0, -10);
                break;
            }
            default: break;
        }
}

void GameManager::CheckEvents()
{
    while (MainWindow->pollEvent(MainEvent))
    {
        switch (MainEvent.type)
        {
            case sf::Event::Closed:
            {
                MainWindow->close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                CheckKeyboard();
                break;
            }
            case sf::Event::KeyReleased:
            {
                CheckKeyboardRelease();
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                CheckMousePress();
                break;
            }
            default: break;
        }
    }
}

void GameManager::ClearWindow()
{
    MainWindow->clear();
}

void GameManager::DrawObjects()
{
    MainGraphicsManager.DrawGameObjects();
    MainWindow->display();
}

void GameManager::UpdateObjects()
{
    MainPhysicsManager.UpdateGameObjects();
}

void GameManager::RunGame()
{
    // Start the game loop
    while (MainWindow->isOpen())
    {
        CheckEvents();
        
        UpdateObjects();
        ClearWindow();
        DrawObjects();
    }
}

GameManager* GameManager::getInstance()
{
    return this;
}

Board* GameManager::getBoardInstance()
{
    return &TheBoard;
}
