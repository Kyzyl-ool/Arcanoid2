//
//  MainManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 28.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef MainManager_hpp
#define MainManager_hpp

#include <map>
#include "GameObject.hpp"

class ObjectManager
{
private:
    std::map<GameObject*, GameObject*> gameobjects;
    sf::RenderWindow* window;
    
    
    
public:
    ObjectManager(sf::RenderWindow* window);
    void AddGameObject(GameObject* obj);
    void RemoveGameObject(GameObject* obj);
    std::map <GameObject*, GameObject*>* getGameObjects();
    sf::RenderWindow* getRenderWindow();
};


#endif /* MainManager_hpp */
