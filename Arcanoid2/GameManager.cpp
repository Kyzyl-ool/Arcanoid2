//
//  GameManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GameManager.hpp"
#include "Defines.h"

#define MAPS_AMOUNT 3

const int maps[MAPS_AMOUNT][MAX_BLOCKS_Y][MAX_BLOCKS_X] =
{
    {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    },
    {
//        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    },
    {
        //        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    }
};


GameManager::GameManager(sf::RenderWindow* iMainWindow):
MainWindow(iMainWindow),
MainObjectManager(new ObjectManager(MainWindow)),
MainGraphicsManager(new GraphicsManager(MainObjectManager)),
MainPhysicsManager(new PhysicsManager(MainObjectManager)),
MainBackground(new Background(0)),
TheBoard(new Board()),
TheBall(new Ball(this)),
TheGameOverText(new GameOverText()),
TheLevelClearedText(new LevelClearedText()),
TheCongratulationsText(new CongratulationsText())
{
    //Creating main game objects
    for (int i = 0; i < MAX_BLOCKS_Y; i++) {
        for (int j = 0; j < MAX_BLOCKS_X; j++) {
            Bricks[i][j] = new Brick(0, j*BLOCK_WIDTH, i*BLOCK_HEIGHT);
            Bricks[i][j]->Deactivate();
            MainObjectManager->AddGameObject(Bricks[i][j]);
        }
    }
    
    LoadMap(0);
    
    //    Loading all game objects to game manager's array
    MainObjectManager->AddGameObject(MainBackground);
    MainObjectManager->AddGameObject(TheBoard);
    MainObjectManager->AddGameObject(TheBall);
    MainObjectManager->AddGameObject(TheGameOverText);
    MainObjectManager->AddGameObject(TheLevelClearedText);
    MainObjectManager->AddGameObject(TheCongratulationsText);
    
    TheLevelClearedText->Deactivate();
    TheGameOverText->Deactivate();
    TheCongratulationsText->Deactivate();
//    for (int i = 0; i < MAX_BLOCKS_Y; i++)
//    {
//        for (int j = 0; j < MAX_BLOCKS_X; j++)
//            if (Bricks[i] != nullptr)
//            {
//
//            }
//    }
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
            TheBoard->setVelocity(20);
            break;
        }
        case sf::Keyboard::Left:
        {
            TheBoard->setVelocity(-20);
            break;
        }
        case sf::Keyboard::Space:
        {
            if (level_cleared)
            {
                level_cleared = false;
                
                TheLevelClearedText->Deactivate();
                TheBall->catch_by_mouse();
                
                if (current_map_number < MAPS_AMOUNT-1)
                {
                    LoadMap(++current_map_number);
                    MainBackground->set_number(current_map_number);
                    
                    TheBall->Activate();
                    TheBoard->Activate();
                }
                else
                {
                    MakeCongratulationsText();
                    TheBoard->Deactivate();
                    TheBall->Deactivate();
                }
            }
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
            TheBoard->setVelocity(0);
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
                TheBall->release();
                TheBall->setVelocity(0, -10);
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
    MainGraphicsManager->DrawGameObjects();
    MainWindow->display();
}

void GameManager::UpdateObjects()
{
    MainPhysicsManager->UpdateGameObjects();
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

void GameManager::MakeGameOverText()
{
//    MainObjectManager->AddGameObject(TheGameOverText);
    TheGameOverText->Activate();
}

void GameManager::MakeLevelClearedText()
{
//    MainObjectManager->AddGameObject(TheLevelClearedText);
    TheLevelClearedText->Activate();
    level_cleared = true;
}

void GameManager::LoadMap(int map_number)
{
    MainObjectManager->reset_amount_of_bricks();
    
    for (int i = 0; i < MAX_BLOCKS_Y; ++i) {
        for (int j = 0; j < MAX_BLOCKS_X; j++) {
            Bricks[i][j]->Deactivate();
            if (maps[map_number][i][j] != -1)
            {
                Bricks[i][j]->setSort(maps[map_number][i][j]);
                Bricks[i][j]->Activate();
                MainObjectManager->inc_amount_of_bricks();
            }
        
        }
    }
}

void GameManager::DestroyBoard()
{
//    TheBoard->set_must_be_deleted(true);
    TheBoard->Deactivate();
}

void GameManager::DestroyBall()
{
//    TheBall->set_must_be_deleted(true);
    TheBall->Deactivate();
}

bool GameManager::isBlocksLeft()
{
    return MainObjectManager->is_blocks_elpased();
}

void GameManager::MakeCongratulationsText()
{
//    MainObjectManager->AddGameObject(TheCongratulationsText);
    TheCongratulationsText->Activate();
}

void GameManager::BallFelt()
{
    MakeGameOverText();
    DestroyBall();
    DestroyBoard();
}

void GameManager::LevelComplete()
{
    MakeLevelClearedText();
    DestroyBoard();
    DestroyBall();
}
