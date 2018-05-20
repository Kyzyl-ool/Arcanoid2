//
//  PhysicsManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "PhysicsManager.hpp"
PhysicsManager::PhysicsManager():
amount_of_game_objects(0)
{
    
}

void PhysicsManager::AddGameObject(GameObject* obj)
{
    gameobjects[amount_of_game_objects++] = obj;
}

void PhysicsManager::UpdateAllObjects()
{
    for (int i = 0; i < amount_of_game_objects; i++)
        for (int j = 0; j < amount_of_game_objects; j++)
            if (i != j)
            {
                if (gameobjects[i]->collideCheck(gameobjects[j]))
                {
                    gameobjects[i]->collideResponse(gameobjects[j]);
                    //                    gameobjects[j]->collideResponse(gameobjects[i]);
                }
            }
    
    for (int i = 0; i < amount_of_game_objects; i++)
    {
        gameobjects[i]->update(dt);
    }
    
}
