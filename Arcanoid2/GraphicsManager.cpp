//
//  GraphicsManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager(sf::RenderWindow* window_pointer):
window(window_pointer),
amount_of_game_objects(0)
{
    
}

void GraphicsManager::DrawAllObjects()
{
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        gameobjects[i]->draw(window);
    }
}

void GraphicsManager::AddGameObject(GameObject *obj)
{
    assert(amount_of_game_objects <= AMOUNT_OF_GAME_OBJECTS);
    gameobjects[amount_of_game_objects++] = obj;
}

