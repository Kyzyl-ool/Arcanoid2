//
//  Background.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef Background_hpp
#define Background_hpp

#include <GameObject.hpp>

class Background: public GameObject
{
private:
    int sort;
    
public:
    Background(int the_type);
    
    void draw(sf::RenderWindow* window);
};

#endif /* Background_hpp */
