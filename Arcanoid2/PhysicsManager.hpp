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
#include "MainManager.hpp"

const float dt = 0.12;
//sf::Clock clocks;

class PhysicsManager
{
private:
    MainManager* MM;
    
public:
    PhysicsManager(MainManager* MM);
    
    void UpdateGameObjects();
};


#endif /* PhysicsManager_hpp */
