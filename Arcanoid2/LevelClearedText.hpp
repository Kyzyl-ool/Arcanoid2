//
//  LevelClearedText.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef LevelClearedText_hpp
#define LevelClearedText_hpp

#include "GameObject.hpp"

class LevelClearedText: public GameObject
{
public:
    LevelClearedText();
    void draw(sf::RenderWindow* window);
};

#endif /* LevelClearedText_hpp */
