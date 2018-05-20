//
//  GraphicsManager.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef GraphicsManager_hpp
#define GraphicsManager_hpp

#include "GameObjects.h"

class GraphicsManager
{
private:
    sf::RenderWindow* window;
    GameObject* gameobjects[AMOUNT_OF_GAME_OBJECTS] = {nullptr};
    int amount_of_game_objects;
    
    
public:
    GraphicsManager(sf::RenderWindow* window_pointer);
    //    ~GraphicsManager();
    
    void AddGameObject(GameObject* obj);
    void DrawAllObjects();
};

#endif /* GraphicsManager_hpp */
