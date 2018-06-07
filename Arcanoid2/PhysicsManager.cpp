//
//  PhysicsManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "PhysicsManager.hpp"
#include <stack>

PhysicsManager::PhysicsManager(ObjectManager* MM):
MM(MM)
{
    
}

void PhysicsManager::UpdateGameObjects()
{
    std::stack<GameObject*> Grave;
    for (auto it = MM->getGameObjects()->begin(); it != MM->getGameObjects()->end(); ++it) {
        if (is_valid_object(it->first) && it->first->is_must_be_deleted())
        {
            Grave.push(it->first);
        }
    }
    while (!Grave.empty())
    {
        MM->RemoveGameObject(Grave.top());
        Grave.pop();
    }
    
    for (auto it = MM->getGameObjects()->begin(); it != MM->getGameObjects()->end(); ++it) {
        for (auto jt = MM->getGameObjects()->begin(); jt != MM->getGameObjects()->end(); ++jt) {
            if (is_valid_object(it->first) && is_valid_object(jt->first) && it->first != jt->first)
            {
                if (it->first->collideCheck(jt->first))
                {
                    it->first->collideResponse(jt->first);
                    jt->first->collideResponse(it->first);
                }
            }
        }
    }
    
    for (auto it = MM->getGameObjects()->begin(); it != MM->getGameObjects()->end(); ++it) {
        if (is_valid_object(it->first))
            it->first->update(dt);
    }
}

bool PhysicsManager::is_valid_object(GameObject *obj)
{
    return (obj != nullptr && obj->is_active()) ? true : false;
}
