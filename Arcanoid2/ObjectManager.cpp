//
//  ObjectManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 28.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "ObjectManager.hpp"

ObjectManager::ObjectManager(sf::RenderWindow* window):
window(window),
amount_of_bricks(0)
{

}

void ObjectManager::AddGameObject(GameObject *obj)
{
    gameobjects[obj] = obj;
}

void ObjectManager::RemoveGameObject(GameObject *obj)
{
    if (obj->who() == BLOCK) amount_of_bricks--;
    gameobjects.erase(obj);
//    gameobjects[obj] = nullptr;
    obj->~GameObject();
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

void ObjectManager::inc_amount_of_bricks()
{
    amount_of_bricks++;
}

void ObjectManager::reset_amount_of_bricks()
{
    amount_of_bricks = 0;
}
