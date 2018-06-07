//
//  Button.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 07.06.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>
#include "Defines.h"

class Button
{
protected:
    float x, y;
    float width, height;
    sf::Font Font;
    
public:
    Button();
    
    virtual void Action() {};
    virtual void Draw(sf::RenderWindow* window) {};
};

#endif /* Button_hpp */
