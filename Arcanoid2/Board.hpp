//
//  Board.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <GameObject.hpp>
#include "GameTypes.h"

enum support_length
{
    SUPPORT_SHORT = 44,
    SUPPORT_NORMAL = 88,
    SUPPORT_LONG = 132,
    SUPPORT_VERY_LONG = 176
};

class Board: public GameObject
{
private:
    sf::Sprite sprite2;
    int length;
    int screen_size;
    double velocity;
    
    Rect collisionRectangles[3];
    
public:
    Board();
    
    void draw(sf::RenderWindow* window);
    
    double getVelocity();
    int getLength();
    Rect getRect(int n);
    
    void setVelocity(double v);
    
    void update(float dt);
    void reduceVelocity();
    
    void dump();
};



#endif /* Board_hpp */
