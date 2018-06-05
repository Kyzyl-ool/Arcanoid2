//
//  MainManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 28.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "ObjectManager.hpp"

ObjectManager::ObjectManager(sf::RenderWindow* window):
window(window)
{

}

void ObjectManager::AddGameObject(GameObject *obj)
{
    gameobjects[obj] = obj;
    if (obj->who() == BLOCK) amount_of_bricks++;
}

void ObjectManager::RemoveGameObject(GameObject *obj)
{
    gameobjects.erase(obj);
}

sf::RenderWindow* ObjectManager::getRenderWindow()
{
    return window;
}

std::map <GameObject*, GameObject*>* ObjectManager::getGameObjects()
{
    return &gameobjects;
}

bool ObjectManager::is_blocks_elpased()
{
    return (amount_of_bricks > 0) ? true : false;
}
