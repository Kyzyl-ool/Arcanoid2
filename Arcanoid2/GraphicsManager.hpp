//
//  GraphicsManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef GraphicsManager_hpp
#define GraphicsManager_hpp

#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include "ObjectManager.hpp"


class GraphicsManager
{
private:
    ObjectManager* MM;
    
public:
    GraphicsManager(ObjectManager* MM);
    void DrawGameObjects();
    
    bool is_valid_object(GameObject* obj);
};

#endif /* GraphicsManager_hpp */
