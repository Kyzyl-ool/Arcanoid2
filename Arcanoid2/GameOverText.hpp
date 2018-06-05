//
//  GameOverText.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 05.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef GameOverText_hpp
#define GameOverText_hpp

#include "GameObject.hpp"

class GameOverText: public GameObject
{
public:
    GameOverText();
    void draw(sf::RenderWindow*);
};

#endif /* GameOverText_hpp */
