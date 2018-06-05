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
#include "ObjectManager.hpp"

const float dt = 0.7;
//sf::Clock clocks;

class PhysicsManager
{
private:
    ObjectManager* MM;
    
public:
    PhysicsManager(ObjectManager* MM);
    
    void UpdateGameObjects();
};


#endif /* PhysicsManager_hpp */
