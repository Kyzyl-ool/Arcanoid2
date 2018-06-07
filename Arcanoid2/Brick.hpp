//
//  Brick.hpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#ifndef Brick_hpp
#define Brick_hpp

#include <GameObject.hpp>
#include "GameTypes.h"

#define AMOUNT_OF_SORTS 3

const int sort_health[AMOUNT_OF_SORTS] = {1, 2, 3};

class Brick: public GameObject
{
private:
    void* GM;
    int sort;
    int health;
    
    Rect collisionRectangles[4];
    
public:
    Brick(int the_sort, int ix, int iy, void* GM);
    
    void update(float);
    void draw(sf::RenderWindow* window);
    void collideResponse(GameObject* obj);
    
    void getDamage();
    
    void setSort(int isort);
//    void setHealth(int ihealth);
    
    Rect getRect(int n);
};


#endif /* Brick_hpp */
