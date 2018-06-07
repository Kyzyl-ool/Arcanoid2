//
//  GraphicsManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "GraphicsManager.hpp"



GraphicsManager::GraphicsManager(ObjectManager* MM):
MM(MM)
{

}

void GraphicsManager::DrawGameObjects()
{
    for (auto it = MM->getGameObjects()->begin(); it != MM->getGameObjects()->end(); ++it) {
        if (is_valid_object(it->first) && it->first->who() == BACKGROUND)
            it->first->draw(MM->getRenderWindow());
    }
    
    for (auto it = MM->getGameObjects()->begin(); it != MM->getGameObjects()->end(); ++it) {
        if (is_valid_object(it->first) && it->first->who() != BACKGROUND)
            it->first->draw(MM->getRenderWindow());
    }
    
}

bool GraphicsManager::is_valid_object(GameObject *obj)
{
    return (obj != nullptr && obj->is_active()) ? true : false;
}
