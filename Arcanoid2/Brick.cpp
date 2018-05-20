//
//  Brick.cpp
//  Arcanoid2
//
//  Created by Кежик Кызыл-оол on 18.05.2018.
//  Copyright © 2018 Кежик Кызыл-оол. All rights reserved.
//

#include "Brick.hpp"

int get_brick_coord_x(int sort)
{
    return sort*BLOCK_WIDTH/2;
}
int get_brick_coord_y(int health)
{
    return (health-1)*BLOCK_HEIGHT/2;
}

Brick::Brick(int the_sort, int ix, int iy):
sort(the_sort),
health(3)
{
    type = BLOCK;
    
    x = ix;
    y = iy;
    x2 = x + BLOCK_WIDTH;
    y2 = y + BLOCK_HEIGHT;
    texture.loadFromFile(DEFAULT_BLOCKS_FILE);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(
                                      get_brick_coord_x(sort),
                                      get_brick_coord_y(health),
                                      BLOCK_WIDTH/2,
                                      BLOCK_HEIGHT/2));
    sprite.setScale(2, 2);
    sprite.setPosition(x, y);
    
    collisionRectangles[0] = {ix, iy+BLOCK_HEIGHT, ix+BLOCK_WIDTH, iy+BLOCK_HEIGHT+BALL_SIZE/2};
    collisionRectangles[1] = {ix - BALL_SIZE/2, iy, ix, iy + BLOCK_HEIGHT};
    collisionRectangles[2] = {ix + BLOCK_WIDTH, iy, ix + BLOCK_WIDTH + BALL_SIZE/2, iy + BLOCK_HEIGHT};
    collisionRectangles[3] = {ix, iy - BALL_SIZE/2, ix + BLOCK_WIDTH, iy};
    
}

void Brick::update()
{
    sprite.setTextureRect(sf::IntRect(
                                      get_brick_coord_x(sort),
                                      get_brick_coord_y(health),
                                      BLOCK_WIDTH/2,
                                      BLOCK_HEIGHT/2));
}

void Brick::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

void Brick::getDamage()
{
    if (health > 0)
        health--;
}

void Brick::collideResponse(GameObject *obj)
{
    switch (obj->who())
    {
        case BALL:
            getDamage();
            break;
        default:
            break;
    }
}

Rect Brick::getRect(int n)
{
    assert(n < BRICK_AMOUNT_OF_COLLISION_RECTANGLES && n >= 0);
    return collisionRectangles[n];
}
