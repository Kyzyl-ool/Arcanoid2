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

typedef struct Rect
{
    int x1, y1, x2, y2;
}Rect;

class Brick: public GameObject
{
private:
    int sort;
    int health;
    int x2, y2;
    
    Rect collisionRectangles[4];
    
public:
    Brick(int the_sort, int ix, int iy);
    
    void update();
    void draw(sf::RenderWindow* window);
    void collideResponse(GameObject* obj);
    
    void getDamage();
    
    Rect getRect(int n);
};


#endif /* Brick_hpp */
