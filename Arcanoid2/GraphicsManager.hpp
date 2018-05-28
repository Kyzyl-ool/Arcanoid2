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
#include "MainManager.hpp"


class GraphicsManager
{
private:
    MainManager* MM;
    
public:
    GraphicsManager(MainManager* MM);
    void DrawGameObjects();
    
};

#endif /* GraphicsManager_hpp */
