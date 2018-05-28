//
//  MainManager.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 28.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "MainManager.hpp"

MainManager::MainManager(sf::RenderWindow* window):
window(window)
{

}

void MainManager::AddGameObject(GameObject *obj)
{
    gameobjects[obj] = obj;
}

void MainManager::RemoveGameObject(GameObject *obj)
{
    gameobjects.erase(obj);
}

sf::RenderWindow* MainManager::getRenderWindow()
{
    return window;
}

std::map <GameObject*, GameObject*>* MainManager::getGameObjects()
{
    return &gameobjects;
}
