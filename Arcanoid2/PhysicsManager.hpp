//
//  PhysicsManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include "GameObjects.h"
#include "Defines.h"

const float dt = 0.1;
//sf::Clock clocks;

class PhysicsManager
{
private:
    GameObject* gameobjects[AMOUNT_OF_GAME_OBJECTS] = {nullptr};
    int amount_of_game_objects;
    
public:
    PhysicsManager();
    
    void AddGameObject(GameObject* obj);
    void UpdateAllObjects();
};


#endif /* PhysicsManager_hpp */
