//
//  MenuBackground.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef MenuBackground_hpp
#define MenuBackground_hpp

#include "GameObject.hpp"

class MenuBackground: public GameObject
{
public:
    MenuBackground();
    
    void draw(sf::RenderWindow* window);
};

#endif /* MenuBackground_hpp */
